/*
 * Lumber.h
 *
 *  Created on: 04-Oct-2019
 *      Author: Yogesh Kalwar
 */

#ifndef APPARATUS_UTILS_LUMBER_H_
#define APPARATUS_UTILS_LUMBER_H_
#include <string>
class Lumber {

	public:
		static void init(bool debug);
		static void d(std::string tag, std::string message);

	private:
		Lumber();
		virtual ~Lumber();

		static bool gDebug;
};

#endif /* APPARATUS_UTILS_LUMBER_H_ */
