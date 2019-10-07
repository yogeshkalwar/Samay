/*
 * SLooper.h
 *
 *  Created on: 04-Oct-2019
 *      Author: yogkalwa
 */

#ifndef APPARATUS_CORE_SLOOPER_H_
#define APPARATUS_CORE_SLOOPER_H_
#include "SMessageQueue.h"
#include "SThread.h"
#include "map"

class SMessageQueue;

class SLooper {
	public:
		SLooper();
		virtual ~SLooper();
		SMessageQueue* getMessageQueue();
		static void prepareMainLooper();
		static SLooper* getMainLooper();
		static SLooper* getCurrentLooper();
		static void loop();
		static void shut();
	private:
		static void prepare();
		static SLooper* gMainLooper;
		static std::map<Thread_ID, SLooper> gThreadLocal;
		SMessageQueue* mQueue;
		SThread mThread;
};

#endif /* APPARATUS_CORE_SLOOPER_H_ */
