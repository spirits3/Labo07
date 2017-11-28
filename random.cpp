/*
 -----------------------------------------------------------------------------------
 Laboratory : 07 generateur aleatoire
 File       : random.cpp
 Author(s)  : Fulgencio Esteves Jorge-Andre, Schaufelberger Florian
 Date       : 27.11.2017

 Aim        : Function library for random number generation

 Comment(s) : Seeded once per function

 Compiler   : MinGW-g++ 4.9.2
 -----------------------------------------------------------------------------------
 */
#include <ctime>
#include <cstdlib>

 /**
  * Returns a random integer between two given values
  *
  * @param lowerBound	the minimal value returned by the random integer generator
  * @param upperBound	the maximal value returned by the random integer generator
  *
  * @return 	a random integer between two given values (values included)
  */
int randomInt(int lowerBound = 0, int upperBound = RAND_MAX) {
	static bool seeded = false;

	if (!seeded) {
		srand(time(nullptr));
		seeded = true;
	}

	return rand() % (upperBound - lowerBound) + lowerBound;
}
