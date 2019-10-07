/*
 * SMessageHandler.cpp
 *
 *  Created on: 05-Oct-2019
 *      Author: Yogesh Kalwar
 */

#include "SMessageHandler.h"
#include "SRuntimeException.h"

SMessageHandler::SMessageHandler(SLooper* looper) {
	mMessageQueue = looper->getMessageQueue();
}

SMessageHandler::~SMessageHandler() {
	// TODO Auto-generated destructor stub
}

bool SMessageHandler::sendMessageAtTime(SMessage* msg, long when) {
	checkMessageQueueIfNull();
	SMessageQueue* msgQueue = mMessageQueue;
	return msgQueue->enqueue(msg, when);
}

void SMessageHandler::removeMessage(SMessage* msg) {
	checkMessageQueueIfNull();
	mMessageQueue->dequeue(msg);
}

void SMessageHandler::removeMessage(EventCode code) {
	checkMessageQueueIfNull();
	mMessageQueue->dequeue(code);
}

void SMessageHandler::checkMessageQueueIfNull() {
	if (mMessageQueue == NULL) {
		throw new SRuntimeException("SendMessage() called on null message queue");
	}
}
