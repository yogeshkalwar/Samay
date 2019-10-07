/*
 * SRuntimeException.cpp
 *
 *  Created on: 04-Oct-2019
 *      Author: Yogesh Kalwar
 */

#include "SRuntimeException.h"

SRuntimeException::SRuntimeException(const std::string& what_arg) : std::runtime_error(what_arg) {
}
