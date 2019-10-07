/*
 * Lumber.cpp
 *
 *  Created on: 04-Oct-2019
 *      Author: Yogesh Kalwar
 */
#include <stdio.h>
#include "Lumber.h"

bool Lumber::gDebug;

Lumber::Lumber() {
	// TODO Auto-generated constructor stub
}

Lumber::~Lumber() {
	// TODO Auto-generated destructor stub
}

void Lumber::init(bool debug) {
	gDebug = debug;
}

void Lumber::d(std::string tag, std::string message) {
	if (gDebug) {
		printf("%s => %s\n", tag.c_str(), message.c_str());
	}
}
