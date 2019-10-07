/*
 * SMessage.h
 *
 *  Created on: 05-Oct-2019
 *      Author: Yogesh Kalwar
 */

#ifndef APPARATUS_CORE_SMESSAGE_H_
#define APPARATUS_CORE_SMESSAGE_H_
#include <string>
#include "SMessageData.h"
#include "SMessageHandler.h"
#include "SEvent.h"
#include "SMessage.h"

class SMessageHandler;

class SMessage {//FIXME: make it serializable
	public:
		SMessage();
		virtual ~SMessage();
		void recylce();
		std::string toString();

		EventCode mCode;
		int mArg;
		SMessageData mData;
		SMessageHandler* mHandler;
		long mWhen;
		SMessage* mNext;
		bool mInUse;
};

#endif /* APPARATUS_CORE_SMESSAGE_H_ */
