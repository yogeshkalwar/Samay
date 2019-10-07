/*
 * SMessageHandler.h
 *
 *  Created on: 05-Oct-2019
 *      Author: Yogesh Kalwar
 */

#ifndef APPARATUS_CORE_SMESSAGEHANDLER_H_
#define APPARATUS_CORE_SMESSAGEHANDLER_H_
#include "SLooper.h"
#include "SEvent.h"
#include "SMessage.h"
#include "SMessageQueue.h"

class SLooper;
class SMessage;
class SMessageQueue;

class SMessageHandler {
	public:
		SMessageHandler(SLooper* looper);
		bool sendMessageAtTime(SMessage* msg, long when);
		void removeMessage(SMessage* msg);
		void removeMessage(EventCode code);
		virtual ~SMessageHandler();
		void processMessage(SMessage* msg);
	private:
		SMessageQueue* mMessageQueue;
		void checkMessageQueueIfNull();
};

#endif /* APPARATUS_CORE_SMESSAGEHANDLER_H_ */
