/*
 * SApplicationHandler.h
 *
 *  Created on: 05-Oct-2019
 *      Author: Yogesh Kalwar
 */

#ifndef APPARATUS_CORE_SAPPLICATIONHANDLER_H_
#define APPARATUS_CORE_SAPPLICATIONHANDLER_H_
#include "SMessageHandler.h"
#include "SLooper.h"

class SApplicationHandler : public SMessageHandler {
	public:
		SApplicationHandler(SLooper* looper);
		virtual ~SApplicationHandler();
		void processMessage(SMessage* msg);
};

#endif /* APPARATUS_CORE_SAPPLICATIONHANDLER_H_ */
