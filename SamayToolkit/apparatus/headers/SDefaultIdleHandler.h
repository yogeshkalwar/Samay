/*
 * SDefaultIdleHandler.h
 *
 *  Created on: 05-Oct-2019
 *      Author: Yogesh Kalwar
 */

#ifndef APPARATUS_CORE_SDEFAULTIDLEHANDLER_H_
#define APPARATUS_CORE_SDEFAULTIDLEHANDLER_H_
#include <chrono>
#include <thread>
#include "SIdleHandler.h"
#include "Lumber.h"

static const long SLEEP = 1000;
class SDefaultIdleHandler : public SIdleHandler {
	public:
		bool isIdle() {
			Lumber::d("SDefaultIdleHandler", "Idle handler going to sleep for " + std::to_string(SLEEP) + " ms.");
			std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP));
			return false;
		}
};

#endif /* APPARATUS_CORE_SDEFAULTIDLEHANDLER_H_ */
