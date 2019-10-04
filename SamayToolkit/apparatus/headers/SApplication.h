/*
 * SApplication.h
 *
 *  Created on: 03-Oct-2019
 *      Author: Yogesh Kalwar
 */

#ifndef APPARATUS_MAIN_SAPPLICATION_H_
#define APPARATUS_MAIN_SAPPLICATION_H_

class SApplication;

SApplication* getApp();

enum AppState {
	SUCCESS,
	FAILED
};

enum EventCode {
	CLOSE_APP
};

class SApplication {

		friend SApplication* getApp();

	public:
		SApplication();
		virtual ~SApplication();
		virtual AppState init() = 0;
		virtual void deInit();

	protected:
		static SApplication *gApp;

	private:
		EventCode start();
		void initLooper();

};

#endif /* APPARATUS_MAIN_SAPPLICATION_H_ */
