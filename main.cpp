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
    const int    YEAR_MIN = 1900,
                 YEAR_MAX = 2100;
    const char   YES      = 'o';
    const char   NO       = 'n';

    const string QUESTION_REDO          = string("Voulez-vous recommencer [") + YES + "," + NO + "] ? ",
                 QUESTION_DATE          = "Veuillez entrer une date de ",
                 DATE_FORMAT            = "[dd-mm-yyyy]",

                 QUESTION_DATE_START    = QUESTION_DATE + "depart " + DATE_FORMAT + " : ",
                 QUESTION_DATE_END      = QUESTION_DATE + "fin " + DATE_FORMAT + " : ",

                 ERROR_DATE_WRONG_ORDER = "Les dates ne sont pas dans le bonne ordre !",
                 SUCCESS_DATE_RESULT    = "Le nombre de jours entre ces deux dates sont : ";

    const char  SEPARATOR = '-';
    
    // Input value
    int startDay   = 0,
        startMonth = 0,
        startYear  = 0,
        endDay     = 0,
        endMonth   = 0,
        endYear    = 0;

    cout << "Ce programme calcule le nombre de jours PLEIN entre deux dates." << endl << endl;

    do {
        getEuropeanDate(startDay, startMonth, startYear, YEAR_MIN, YEAR_MAX, QUESTION_DATE_START, SEPARATOR);
        getEuropeanDate(endDay, endMonth, endYear, YEAR_MIN, YEAR_MAX, QUESTION_DATE_END, SEPARATOR);

        int days = nbDaysBetweenDates(startDay, startMonth, startYear, endDay, endMonth, endYear);

        if (days < 0) {
            cout << ERROR_DATE_WRONG_ORDER << endl;
        } else {
            // Exclude the bound to get FULL days
            cout << SUCCESS_DATE_RESULT << --days << endl;
        }
    } while (wantsUserRedo(YES, NO, QUESTION_REDO));


    waitUserInteraction();

    return EXIT_SUCCESS;
}

