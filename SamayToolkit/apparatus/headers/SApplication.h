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

class SApplication {

		friend SApplication* getApp();

	protected:
		static SApplication *gApp;

	public:
		SApplication();
		virtual ~SApplication();
		virtual AppState init() = 0;
};

#endif /* APPARATUS_MAIN_SAPPLICATION_H_ */
