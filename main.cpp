/*
 -----------------------------------------------------------------------------------
 Laboratory : 07 generateur aleatoire
 File       : main.cpp
 Author(s)  : Fulgencio Esteves Jorge-Andre, Schaufelberger Florian
 Date       : 27.11.2017

 Aim        : This program displays graphicaly and through percentages the
 	 	 	  distribution of randomly generated numbers through a number of
 	 	 	  iterations. The number of iterations and the range of value randomly
 	 	 	  generated are given by the user.

 Comment(s) : -The array is created through a variable. May not work for every
 	 	 	   compiler, works for this class.
 	 	 	  -All input must be completely verified
 	 	 	  -Only "C" arays are allowed. No usage of classes such as vectors
 	 	 	  -Every functions must as much 're-usable' as possible

 Compiler   : MinGW-g++ 4.9.2
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "io.h"
#include "misc.h"

using namespace std;

int main(){
	const unsigned int ELEMENTS_MIN = 0,
					   ELEMENTS_MAX = 100,
					   TRIES_MIN    = 0,
					   TRIES_MAX	= 10000;
	const char YES = 'o',
			    NO = 'n';
	const string QUESTION_REDO     = string("Voulez-vous recommencer [") + YES + "," + NO + "] ? :";
	const string QUESTION_ELEMENTS = string("nbre d'elements    [") + to_string(ELEMENTS_MIN)
									 + ".." + to_string(ELEMENTS_MAX) + "] : ";
    const string QUESTION_TRIES    = string("nbre de lances  [") + to_string(TRIES_MIN)
    								 + ".." + to_string(TRIES_MAX) + "] : ";

	do {
		cout << "Ce programme représente graphiquement la répartition "
				"des valeurs générés aléatoirement" << endl;

		unsigned int elements = getIntBetween(ELEMENTS_MIN, ELEMENTS_MAX, QUESTION_ELEMENTS),
					 tries    = getIntBetween(TRIES_MIN, TRIES_MAX, QUESTION_TRIES),
					 tab[elements] = {};
		calculPercentage(tab, tries, elements);
		arrayDisplayer(tab, tries, elements);

	} while (wantsUserRedo(YES,NO, QUESTION_REDO));

	waitUserInteraction();

	return EXIT_SUCCESS;
}
