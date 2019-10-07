/*
 * SThread.cpp
 *
 *  Created on: 04-Oct-2019
 *      Author: Yogesh Kalwar
 */

#include "SThread.h"

SThread::SThread() {
	mThread = NULL;
	mId = std::this_thread::get_id();
}

SThread::SThread(std::thread thread) {
	//mThread = thread;
}

SThread::~SThread() {
	//FIXME: Clear the thread
}

Thread_ID SThread::getThreadId() {
	return mId;
}

Thread_ID SThread::getCurrentThreadId() {
	return std::this_thread::get_id();
}
