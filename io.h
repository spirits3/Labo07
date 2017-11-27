/*
--------------------------------------------------------------------------------------------------------
Laboratory : 05 Calendar
File       : io.h
Author(s)  : Jonathan Zaehringer, Pierre Kohler
Date       : 1.11.2017

Aim        : Header of io.cpp, define macro to clean buffer, reset buffer,
                wait interaction from user and user want redo the software

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or MinGW-g++ 4.9.2 
UPDATE
--------------------------------------------------------------------------------------------------------
Laboratory : 06 Number of Day
Author(s)  : Jonathan Zaehringer, Florian Schaufelberger
Date       : 20.11.2017

Aim        : Not changed

                Adding function to get Date from user

Comment(s) : Using date library to manipulate date from user

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0
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

#endif
