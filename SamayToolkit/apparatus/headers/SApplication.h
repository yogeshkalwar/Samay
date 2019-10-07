/*
 * SApplication.h
 *
 *  Created on: 03-Oct-2019
 *      Author: Yogesh Kalwar
 */

#ifndef APPARATUS_MAIN_SAPPLICATION_H_
#define APPARATUS_MAIN_SAPPLICATION_H_
#include "SEvent.h"
#include "SLooper.h"
#include "SApplicationHandler.h"

class SApplication;

SApplication* getApp();

enum AppState {
	SUCCESS,
	FAILED
};

class SApplication {

		friend SApplication* getApp();

	public:
		SApplication();
		virtual ~SApplication();
		virtual AppState init() = 0;
		virtual void deInit();
		SLooper* getLooper();

	protected:
		static SApplication *gApp;

	private:
		void start();
		void initLooper();
		SApplicationHandler* mApplicationHandler;
};

#endif /* APPARATUS_MAIN_SAPPLICATION_H_ */
