/*
 * SEvent.cpp
 *
 *  Created on: 04-Oct-2019
 *      Author: Yogesh Kalwar
 */

#include "SEvent.h"

SEvent::SEvent() {
	mEventCode = UNKNOWN;
}

SEvent::SEvent(SEvent& other) {
	mEventCode = other.mEventCode;
}

void SEvent::setEventCode(EventCode eventCode) {
	mEventCode = eventCode;
}

SEvent::~SEvent() {
	// TODO Auto-generated destructor stub
}

EventCode SEvent::getEventCode() {
	return mEventCode;
}
