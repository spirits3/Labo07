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

bool isBetween (int x, int min, int max) {
    return x >= min && x <= max;
}

