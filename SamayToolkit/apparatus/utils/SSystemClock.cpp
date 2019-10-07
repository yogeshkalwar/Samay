/*
 * SSystemClock.cpp
 *
 *  Created on: 05-Oct-2019
 *      Author: yogkalwa
 */

#include <ctime>
#include "SSystemClock.h"

SSystemClock::SSystemClock() {
	// TODO Auto-generated constructor stub

}

SSystemClock::~SSystemClock() {
	// TODO Auto-generated destructor stub
}

long SSystemClock::currentMillis() {
	time_t t = std::time(0);
	long int now = static_cast<long int> (t);
	return now;
}
