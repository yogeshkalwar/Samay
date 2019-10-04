/*
 * SApplication.cpp
 *
 *  Created on: 03-Oct-2019
 *      Author: Yogesh Kalwar
 */
#include "SApplication.h"
#include "Lumber.h"

SApplication::SApplication() {
	gApp = this;
	bool debug = false;
	#if DEBUG
		debug = true;
	#endif
	Lumber::init(debug);
	Lumber::d("SApplication<Constructor>", "Your are in SApplication constructor\n");
	initLooper();
}

SApplication* SApplication::gApp = NULL;

SApplication* getApp() {
	return SApplication::gApp;
}

SApplication::~SApplication() {
	// TODO Auto-generated destructor stub
}

void SApplication::deInit() {

}

void SApplication::initLooper() {
	//TODO: create looper

	start();
}

EventCode SApplication::start() {
	EventCode code;

	return code;
}

int main() {
	SApplication* app = NULL;
	app = getApp();
	if (app == NULL) {
		return -1;
	}
	return app->init();
}
