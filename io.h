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


 /**
  * function will ask the user to put a char and will verify if it's a char.
  *
  * @param question		string with our quesetion
  *
  * @return 			return a char
  */
unsigned char getChar(const std::string& question);


 /**
  * function will ask the user to put an int and will verify if it's a char.
  *
  * @param question		string with our quesetion
  *
  * @return 			return an int s
  */
int getInt(const std::string& question);


 /**
  * function will check if our int is between the bounds
  *
  * @param min			minimum bound
  * @param max			maximum bound
  * @param question		string with our quesetion
  *
  * @return 			return an int
  */
int getIntBetween(int min, int max, const std::string& question);


 /**
  * function ask the user if he want to relaunch the programm.
  *
  * @param yes			char who will restart the programm
  * @param no 			char who will stop the programm		
  * @param question		string with our question
  *
  * @return 		return a bool
  * @return 		return a bool
  */
bool wantsUserRedo(const unsigned char& yes,const unsigned char& no, const std::string& question);


 /**
  * function who just wait the user to press enter to quit the programm.
  */
void waitUserInteraction();

 /**
  * function who will trash a char.
  */
void trashChar();

 /**
  * function will get 3 values by the user and will check if the format is correct
  *
  * @param first		first int entered by user
  * @param second		second int entered by user
  * @param third		third int entered by user
  * @param question		string with our quesetion
  * @param separator	sparator beetween our int
  */
void getDate(int& first, int& second, int& third, const std::string& question, char separator = '.');



//TODOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
 /**
  * function will check if the date is an european date
  *
  * @param day			first int entered by user
  * @param second		second int entered by user
  * @param third		third int entered by user
  * @param question		string with our quesetion
  * @param separator	sparator beetween our int
*/
void getEuropeanDate(int& day, int& month, int& year, int min_year, int max_year, const std::string& question, char separator = '.');

// ---------------------
// Printing functions
// ---------------------
void printCell(int value, int width);
void printCell(char value, int width);

void arrayDisplayer(unsigned int tab[], unsigned throws, unsigned elements);

#endif
