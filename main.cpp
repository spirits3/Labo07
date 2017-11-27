/*
--------------------------------------------------------------------------------------------------------
Laboratory : 06 Number of Day
File       : main.cpp
Author(s)  : Jonathan Zaehringer, Florian Schaufelberger
Date       : 20.11.2017

Aim        : Calculating number of FULL day between two dates.
                
                Data from user :
                    - first date  : dd-mm-yyyy
                    - second date : dd-mm-yyyy

Comment(s) : The software take on board the leap year.
                All input error are catch and redo the input demand.

             If the user reverse date, the soft redo the inpud demand.

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0
--------------------------------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <string>
#include <iostream>

#include "date.h"
#include "io.h"

using namespace std;

int main() {
    

    const char  YES      = 'o',
                NO       = 'n';
    const int   MIN_ELEMENTS = 0,
                MAX_ELEMENTS = 100,
                MIN_THROWS   = 0,
                MAX_THROWS   = 10000;


    const string QUESTION_REDO          = string("Voulez-vous recommencer [") + YES + "," + NO + "] ? ",
                 QUESTION_ELEMENT       = string("nbre d'elements ") + "[" + MIN_ELEMENTS + ".." + MAX_ELEMENTS + "] : ",
                 QUESTION_THROWS        = string("nbre de lances ") + "[" + MIN_THROWS + ".." + MAX_THROWS + "] : ";
    
    // Input value
    } while (wantsUserRedo(YES, NO, QUESTION_REDO));


    waitUserInteraction();

    return EXIT_SUCCESS;
}

