/*
 * SLooper.cpp
 *
 *  Created on: 04-Oct-2019
 *      Author: yogkalwa
 */

#include "SLooper.h"
#include "SRuntimeException.h"
#include "Lumber.h"

SLooper* SLooper::gMainLooper;
std::map<Thread_ID, SLooper> SLooper::gThreadLocal;
SLooper::SLooper() {
	// TODO Auto-generated constructor stub

}

SLooper::~SLooper() {
	// TODO Auto-generated destructor stub
}

SMessageQueue* SLooper::getMessageQueue() {
	return mQueue;
}

void SLooper::prepareMainLooper() {
	prepare();
	//TODO: put thread safe
	if (gMainLooper != NULL) {
		throw new SRuntimeException("Main looper is already created");
	}
	gMainLooper = getCurrentLooper();
	//
}

SLooper* SLooper::getMainLooper() {
	return gMainLooper;
}

SLooper* SLooper::getCurrentLooper() {
	return &gThreadLocal[SThread::getCurrentThreadId()];
}

void SLooper::loop() {
	SLooper* looper = getCurrentLooper();
	if (looper == NULL) {
		throw new SRuntimeException("Looper is null, prepare() looper first");
	}
	SMessageQueue* queue = looper->mQueue;
	for(;;){
		SMessage* msg = queue->next();//block call
		if (msg == NULL) {
			//finished
			Lumber::d("SLooper", "Quiting looper");
			return;
		}
		//Process the message
	}
}

void SLooper::shut() {
	//TODO: shut the looper
}

void SLooper::prepare() {
	//FIXME use thread id
	Thread_ID currentThread = SThread::getCurrentThreadId();
	if (gThreadLocal.find(currentThread) != gThreadLocal.end()) {
		throw new SRuntimeException("only one looper can be created for single thread");
	}
	gThreadLocal[currentThread] = SLooper();
}
