/*
 * SMessage.cpp
 *
 *  Created on: 05-Oct-2019
 *      Author: Yogesh Kalwar
 */

#include "SMessage.h"

SMessage::SMessage() {
	// TODO Auto-generated constructor stub

}

SMessage::~SMessage() {
	// TODO Auto-generated destructor stub
}

std::string SMessage::toString() {
	return "Code: " + std::to_string(mCode) + ", Arg1: " + std::to_string(mArg) + ", Data: " + mData.toString();
}

void SMessage::recylce() {
	//FIXME: clear the resources
}
