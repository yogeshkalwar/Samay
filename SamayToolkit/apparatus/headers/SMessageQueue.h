/*
 * SMessageQueue.h
 *
 *  Created on: 04-Oct-2019
 *      Author: yogkalwa
 */

#ifndef APPARATUS_CORE_SMESSAGEQUEUE_H_
#define APPARATUS_CORE_SMESSAGEQUEUE_H_
#include "SMessage.h"
#include "SIdleHandler.h"
#include "SEvent.h"

class SMessage;

class SMessageQueue {

	public:
		SMessageQueue();
		virtual ~SMessageQueue();
		SMessage* next();
		void dispose();
		bool isIdle();
		void quit();
		bool enqueue(SMessage* msg, long when);
		void dequeue(SMessage* msg);
		void dequeue(EventCode code);

	private:
		bool mIsQuitting;
		SMessage* mMessage;
		SIdleHandler* mIdleHandler;

		void clearAllMessages();
};

#endif /* APPARATUS_CORE_SMESSAGEQUEUE_H_ */
