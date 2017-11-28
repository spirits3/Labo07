/*
--------------------------------------------------------------------------------------------------------
Laboratory : 06 Number of Day
File       : misc.h
Author(s)  : Jonathan Zaehringer, Florian Schaufelberger
Date       : 20.11.2017

Aim        : Miscellaneous function

Comment(s) : 

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0
--------------------------------------------------------------------------------------------------------
*/		

#include "misc.h"
#include "random.h"

using namespace std;

bool isBetween (int x, int min, int max) {
    return x >= min && x <= max;
}

void eachElementByRandom(unsigned int tab[], unsigned int throws, unsigned elements) {
    
    for(int i = 0; i < throws; ++i) {
        tab[randomInt(0, elements)]++;
    }
}

void calculPercentage(unsigned int tab[], unsigned int throws, unsigned elements) {

    eachElementByRandom(tab, throws, elements);
    
    for(int i = 0; i < elements; ++i) {
        tab[i] = tab[i] / (double)throws * 100;
    }
}