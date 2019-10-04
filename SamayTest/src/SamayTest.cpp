//============================================================================
// Name        : SamayTest.cpp
// Author      : Yogesh Kalwar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SApplication.h"

using namespace std;

class MyApplication : public SApplication {

	AppState init() {
		printf("Welcome Samay Test\n");
		return AppState::SUCCESS;
	}
};
MyApplication myApp;
