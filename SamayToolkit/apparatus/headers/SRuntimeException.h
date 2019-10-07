/*
 * SRuntimeException.h
 *
 *  Created on: 04-Oct-2019
 *      Author: yogkalwa
 */

#ifndef APPARATUS_ERROR_SRUNTIMEEXCEPTION_H_
#define APPARATUS_ERROR_SRUNTIMEEXCEPTION_H_
#include<stdexcept>
class SRuntimeException : public std::runtime_error {
	public:
		SRuntimeException(const std::string& what_arg);
};

#endif /* APPARATUS_ERROR_SRUNTIMEEXCEPTION_H_ */
