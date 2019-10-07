/*
 * SApplicationHandler.cpp
 *
 *  Created on: 05-Oct-2019
 *      Author: yogkalwa
 */

#include "SApplicationHandler.h"
#include "Lumber.h"

SApplicationHandler::SApplicationHandler(SLooper* looper) : SMessageHandler(looper) {
	// TODO Auto-generated constructor stub

}

SApplicationHandler::~SApplicationHandler() {
	// TODO Auto-generated destructor stub
}

void SApplicationHandler::processMessage(SMessage* msg) {
	Lumber::d("SApplicationHandler::processMessage()", "msg : " + msg->toString());
}
