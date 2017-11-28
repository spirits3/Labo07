/*
--------------------------------------------------------------------------------------------------------
Laboratory : 07 generateur aleatoire
File       : io.cpp
Author(s)  : Jonathan Zaehringer, Pierre Kohler
Last
Modified by: Florian Schaufelberger, Fulgencio Esteves Jorge-André
Date       : 28.11.2017

Aim        : Header for the signature of the function in io.cpp

Comment(s) : Using date library to manipulate date from user
Modifications : Addition of an array displaying method
Compiler   : MinGW-g++ 4.9.2
--------------------------------------------------------------------------------------------------------
*/

#ifndef IO_HEADER
#define IO_HEADER

#include <string>
#include <iostream>
#include <limits>

#define CLEAN_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define RESET_BUFFER cin.clear(); CLEAN_BUFFER

// ---------------------
// User input functions
// ---------------------
unsigned char getChar(const std::string& question);
int getInt(const std::string& question);
int getIntBetween(int min, int max, const std::string& question);

bool wantsUserRedo(const unsigned char& yes,const unsigned char& no, const std::string& question);
void waitUserInteraction();

void trashChar();
void getDate(int& first, int& second, int& third, const std::string& question, char separator = '.');
void getEuropeanDate(int& day, int& month, int& year, int min_year, int max_year, const std::string& question, char separator = '.');

// ---------------------
// Printing functions
// ---------------------
void printCell(int value, int width);
void printCell(char value, int width);

void arrayDisplayer(unsigned int tab[], unsigned throws, unsigned elements);

#endif
