/*
 * SMessageQueue.cpp
 *
 *  Created on: 04-Oct-2019
 *      Author: yogkalwa
 */

#include <iostream>
#include <math.h>
#include "SMessageQueue.h"
#include "SSystemClock.h"
#include "Lumber.h"
#include "SDefaultIdleHandler.h"
#include "SRuntimeException.h"

using namespace std;

SMessageQueue::SMessageQueue() {
	mIsQuitting = false;
	mMessage = NULL;
	mIdleHandler = new SDefaultIdleHandler();
}

SMessageQueue::~SMessageQueue() {
	dispose();
}

bool SMessageQueue::enqueue(SMessage* msg, long when) {
	bool success = false;
	if (msg != NULL) {
		if (msg->mHandler == NULL) {
			throw new SRuntimeException("Target handler not provided.");
		}
		if (msg->mInUse) {
			throw new SRuntimeException("Message is already in use.");
		}

		//FIXME synchronised this
		if (mIsQuitting) {
			throw new SRuntimeException("Sending message on dead thread");
			msg->recylce();
			return false;
		}
		msg->mInUse = true;
		msg->mWhen = when;
		SMessage* current = mMessage;
		if (current == NULL || when == 0 || when < current->mWhen) {
			//first message or new message is to be processed before top
			msg->mNext = current;
			mMessage = msg;
		} else {
			SMessage* prev = NULL;
			for(;;) {
				prev = current;
				current = current->mNext;
				if (current == NULL || when < current->mWhen) {
					break;
				}
			}
			msg->mNext = current;
			prev->mNext = msg;
		}
		//
		success = true;
	}
	return success;
}

SMessage* SMessageQueue::next() {
	if (mIsQuitting) {
		return NULL;
	}
	//FIXME: synchronised this
	for (;;) {
		const long now = SSystemClock::currentMillis();
		SMessage* msg = mMessage;
		SMessage* prev = NULL;
		long nextIdleTimeout = 0;
		if (msg != NULL) {
			if (now < msg->mWhen) {
				//Message is not ready
				nextIdleTimeout = (int) fmin(msg->mWhen - now, HUGE_VAL);
				do {
					prev = msg;
					msg = msg->mNext;
					if (msg != NULL && msg->mWhen < prev->mWhen) {
						nextIdleTimeout = (int) fmin(msg->mWhen - now, HUGE_VAL);
					}
				} while (msg != NULL && now < msg->mWhen);
			}
			if (msg != NULL) {
				mMessage = msg->mNext;
				Lumber::d("SMessageQueue::next()", "next message for processing " + msg->toString());
				return msg;
			}
		} else {
			nextIdleTimeout = -1;
		}
		//quit if flag raised
		if (mIsQuitting) {
			dispose();
			return NULL;
		}
		mIdleHandler->isIdle();
	}
}

void SMessageQueue::dispose() {

	mIdleHandler = NULL;
}

bool SMessageQueue::isIdle() {
	//FIXME: synchronised this

}

void SMessageQueue::quit() {
	//FIXME synchronised it
	if (mIsQuitting) {
		return;
	}
	mIsQuitting = true;
	clearAllMessages();
}

void SMessageQueue::clearAllMessages() {
	SMessage* msg = mMessage;
	while(msg != NULL) {
		SMessage* next = msg->mNext;
		msg->recylce();
		msg = next;
	}
}

void SMessageQueue::dequeue(SMessage* msg) {
	throw new SRuntimeException("Not imeplemented");
}

void SMessageQueue::dequeue(EventCode code) {
	throw new SRuntimeException("Not imeplemented");
}
