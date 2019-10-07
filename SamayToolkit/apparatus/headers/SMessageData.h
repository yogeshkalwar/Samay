/*
 * SMessageData.h
 *
 *  Created on: 05-Oct-2019
 *      Author: yogkalwa
 */

#ifndef APPARATUS_CORE_SMESSAGEDATA_H_
#define APPARATUS_CORE_SMESSAGEDATA_H_
#include <string>

class SMessageData {
public:
	SMessageData();
	virtual ~SMessageData();
	std::string toString();
};

#endif /* APPARATUS_CORE_SMESSAGEDATA_H_ */
