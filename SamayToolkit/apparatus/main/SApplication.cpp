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
	Lumber::d("SApplication<Constructor>", "Your are in SApplication constructor");
	initLooper();
}

SApplication* SApplication::gApp = NULL;

SApplication* getApp() {
	return SApplication::gApp;
}

SApplication::~SApplication() {
	delete mApplicationHandler;
	mApplicationHandler = NULL;
}

void SApplication::deInit() {

}

void SApplication::initLooper() {
	SLooper::prepareMainLooper();
	mApplicationHandler = new SApplicationHandler(SLooper::getMainLooper());
	start();
}

void SApplication::start() {
	SLooper::getMainLooper()->loop();
	Lumber::d("SApplication<start>", "Closing the application");
}

int main() {
	SApplication* app = NULL;
	app = getApp();
	if (app == NULL) {
		return -1;
	}
	return app->init();
}
