/*
 * SEvent.h
 *
 *  Created on: 04-Oct-2019
 *      Author: Yogesh Kalwar
 */

#ifndef APPARATUS_CORE_SEVENT_H_
#define APPARATUS_CORE_SEVENT_H_

enum EventCode {
	CLOSE_APP,
	UNKNOWN
};

class SEvent {

	public:
		SEvent();
		SEvent(SEvent& other);
		~SEvent();
		void setEventCode(EventCode code);
		EventCode getEventCode();
	private:
		EventCode mEventCode;
};

#endif /* APPARATUS_CORE_SEVENT_H_ */
