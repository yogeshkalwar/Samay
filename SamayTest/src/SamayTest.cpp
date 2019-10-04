//============================================================================
// Name        : SamayTest.cpp
// Author      : Yogesh Kalwar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "SApplication.h"
#include "Lumber.h"

class MyApplication : public SApplication {

	AppState init() {
		Lumber::d("MyApplication", "Welcome Samay Test");
		return SUCCESS;
	}
};
MyApplication myApp;
