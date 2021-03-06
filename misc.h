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
  * returns a bool to know if our value is between our bounds
  *
  * @param x			the value we want to know if it's between our bounds.
  * @param min			the minimal bound 
  * @param max			the maximal bound 
  *
  * @return 	return a bool if our value is between our bounds
  */
bool isBetween(int x, int min, int max);

 /**
  * will increase the number of time our elements of tab was call by a random function
  *
  * @param tab			tab where we will increase our value.
  * @param throws		number of times we will throw our dice and will give us a random number
  * @param elements		number of elements in our tab 
  *
  */
void eachElementByRandom(unsigned int tab[], unsigned int throws, unsigned elements);


 /**
  * will calculate the percentage of how many throws was the same as one of our element.
  *
  * @param tab			tab where we will increase our value.
  * @param throws		number of times we will throw our dice and will give us a random number
  * @param elements		number of elements in our tab 
  *
  */
void calculPercentage(unsigned int tab[], unsigned int throws, unsigned elements);

#endif
