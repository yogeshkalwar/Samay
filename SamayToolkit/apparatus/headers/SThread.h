/*
 * SThread.h
 *
 *  Created on: 04-Oct-2019
 *      Author: Yogesh Kalwar
 */

#ifndef APPARATUS_CORE_STHREAD_H_
#define APPARATUS_CORE_STHREAD_H_
#include <thread>

typedef std::thread::id Thread_ID;

class SThread {
	public:
		SThread();
		SThread(std::thread thread);
		virtual ~SThread();
		Thread_ID getThreadId();
		static Thread_ID getCurrentThreadId();
	private:
		std::thread* mThread;
		Thread_ID mId;
};

#endif /* APPARATUS_CORE_STHREAD_H_ */
