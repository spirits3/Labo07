/*
--------------------------------------------------------------------------------------------------------
Laboratory : 07 generateur aleatoire
File       : misc.h
Author(s)  : Jonathan Zaehringer, Pierre Kohler

Last
Modified by: Fulgencio Esteves Jorge-Andre, Schaufelberger Florian
Date       : 28.11.2017

Aim        : Header for miscellaneous macros and signature of functions in misc.cpp 

Comment(s) : 

Modifications : Addition of array generating methods for the lab07
Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or MinGW-g++ 4.9.2 
--------------------------------------------------------------------------------------------------------
*/

#ifndef MISC_HEADER
#define MISC_HEADER

// Macro to use 'unless' and 'until' statements 
#define unless(x) if(!(x))
#define until(x) while(!(x))

/**
 * Determines whether a integer is contained in a interval
 *
 * @param x
 * @param min
 * @param max
 */
bool isBetween(int x, int min, int max);

/**
 * Generates a number of random generated throws and counts each appearance of a certain
 * random element and stores it at a tab index.
 *
 * @param tab		the array containing the number of apperance of a certain number
 * 					tab[i] will contain the number of times 0 appeared in x throws
 * @param throws	the total number of randomly generated numbers
 * @param elements	the number of elements in the array also the range for the random generation
 */
void eachElementByRandom(unsigned int tab[], unsigned int throws, unsigned elements);

/**
 *
 */
void calculPercentage(unsigned int tab[], unsigned int throws, unsigned elements);

#endif
