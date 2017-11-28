/*
--------------------------------------------------------------------------------------------------------
Laboratory : 05 Calendar
File       : io.cpp
Author(s)  : Jonathan Zaehringer, Pierre Kohler
Date       : 1.11.2017

Aim        : Library to interacte with user and display a table

Comment(s) : 

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or MinGW-g++ 4.9.2 

UPDATE
--------------------------------------------------------------------------------------------------------
Laboratory : 06 Number of Day
File       : io.cpp
Author(s)  : Jonathan Zaehringer, Florian Schaufelberger
Date       : 20.11.2017

Aim        : Not changed

                Adding function to get Date from user

Comment(s) : Using date library to manipulate date from user

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0
--------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include <string>

#include "date.h"
#include "misc.h"
#include "random.h"

#include "io.h"



using namespace std;

// -------------------------------
// User input functions
// -------------------------------

unsigned char getChar(const string& question) {
    const string ERROR = "La valeur n'est pas un caractère.";

    unsigned char result;
    bool badValue;

    do {
        cout << question;
        cin >> result;

        if ((badValue = cin.fail())) {
            RESET_BUFFER;
        }

    } while (badValue && cout << ERROR << endl);

    CLEAN_BUFFER;

    return result;
}

int getInt(const string& question) {
    const string ERROR = "La valeur n'est pas un entier.";

    int result;
    bool badValue;

    do {
        cout << question;
        cin >> result;

        if ((badValue = cin.fail())) {
            RESET_BUFFER;
        }

    } while (badValue && cout << ERROR << endl);

    CLEAN_BUFFER;

    return result;
}

bool getInt(int& value) {
    cin >> value;

    if (cin.fail()) {
        RESET_BUFFER;
        return true;
    }

    return false;   
}

int getIntBetween(int min, int max, const string& question) {
    const string ERROR = string(" n'est pas compris entre ") + to_string(min) + " et " + to_string(max) + ".";

    int result;

    do {
        result = getInt(question);
    } while ((result > max || result < min) && cout << result << ERROR << endl);

    return result;
}

void trashChar(){
    cin.get();
}

void getEuropeanDate(int& day, int& month, int& year, int minYear, int maxYear, const string& question, char separator) {
    const string ERROR_BASE = "La date n'est pas valide ! : ";

    bool validDate;
    string error = ERROR_BASE;

    do {
        validDate = true;

        getDate(day, month, year, question, separator);

        unless (isBetween(year, minYear, maxYear)) {
            error += "\n - L'année n'est pas comprise entre " + to_string(minYear) + " et " + to_string(maxYear) + "."; 
            validDate = false;
        }

        unless (isValidGregorianDate(day, month, year)) {
            error += "\n - La date n'existe pas.";
            validDate = false;
        }
    } while (!validDate && cout << error << endl);
}

void getDate(int& first, int& second, int& third, const string& question, char separator) {
    const string ERROR = "Ceci n'est pas une date",
                 ERROR_FORMAT = ERROR + " : format incorrect";

    // This form, reduce test if the error are find early
    do {
        cout << question;

        if (getInt(first)) {
            cout << ERROR << endl;
            continue;
        }

        if (cin.get() != separator) {
            cout << ERROR_FORMAT << endl;

            CLEAN_BUFFER;
            continue;
        }

        if (getInt(second)) {
            cout << ERROR;
            continue;
        }

        if (cin.get() != separator) {
            cout << ERROR_FORMAT << endl;

            CLEAN_BUFFER;
            continue;
        }

        if (getInt(third)) {
            cout << ERROR;
            continue;
        }

        break;

    } while (true);
    
}

bool wantsUserRedo(const unsigned char& yes,const unsigned char& no, const string& question) {
    const string ERROR = "ne répond pas à la question.";

    unsigned char result;

    do {
        result = getChar(question);
    } while ((result != yes && result != no) && cout << "'" << result << "'" << ERROR << endl);

    return (result == yes);
}

void waitUserInteraction() {
    cout << "presser ENTER pour quitter";
    
    CLEAN_BUFFER;
}

// -------------------------------
// Printing functions
// -------------------------------

void printCell(int value, int width) {
    cout << right << setw(width) << value;
}

void printCell(char value, int width) {
    cout << right << setw(width) << value;
}

void equalDisplayer(unsigned percentage) {

    for(int i = 0; i < percentage; ++i) {
        cout << "=";
    }
    cout << endl;
}

void arrayDisplayer(unsigned int tab[], unsigned throws, unsigned elements) {

    for(int i = 0; i < elements; ++i) {
        cout << "Tableau [" << i << "]     " << tab[i];
        equalDisplayer(tab[i]);
        cout << endl;
    }
}

