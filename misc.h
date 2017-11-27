/*
--------------------------------------------------------------------------------------------------------
Laboratory : 05 Calendar
File       : misc.h
Author(s)  : Jonathan Zaehringer, Pierre Kohler
Date       : 1.11.2017

Aim        : Header for miscellaneous macros and signature of functions in misc.cpp 

Comment(s) : 

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or MinGW-g++ 4.9.2 

UPDATE
--------------------------------------------------------------------------------------------------------
Laboratory : 06 Number of Day
Author(s)  : Jonathan Zaehringer, Florian Schaufelberger
Date       : 20.11.2017

Aim        : Not changed

                Adding function to check int between two bounds 

Comment(s) : 

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0
--------------------------------------------------------------------------------------------------------
*/
#ifndef MISC_HEADER
#define MISC_HEADER

// Macro to use 'unless' and 'until' statements 
#define unless(x) if(!(x))
#define until(x) while(!(x))

bool isBetween(int x, int min, int max);

void eachElementByRandom(int tab[], unsigned throws, unsigned elements);
void calculPercentage(int tab[], unsigned throws);
void equalDisplayer();


#endif
