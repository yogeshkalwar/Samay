/*
 * SApplication.cpp
 *
 *  Created on: 03-Oct-2019
 *      Author: Yogesh Kalwar
 */
#include <stdio.h>
#include <stdlib.h>
#include "SApplication.h"

SApplication::SApplication() {
	gApp = this;
	printf("Your are in SApplication constructor\n");
}

SApplication* SApplication::gApp = NULL;

SApplication* getApp() {
	return SApplication::gApp;
}

SApplication::~SApplication() {
	// TODO Auto-generated destructor stub
}

int main() {
	SApplication* app = NULL;
	app = getApp();
	if (app == NULL) {
		return -1;
	}
	return app->init();
}
