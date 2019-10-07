/*
 * SSystemClock.h
 *
 *  Created on: 05-Oct-2019
 *      Author: yogkalwa
 */

#ifndef APPARATUS_UTILS_SSYSTEMCLOCK_H_
#define APPARATUS_UTILS_SSYSTEMCLOCK_H_

class SSystemClock {
	public:
		SSystemClock();
		virtual ~SSystemClock();
		static long currentMillis();
};

#endif /* APPARATUS_UTILS_SSYSTEMCLOCK_H_ */
