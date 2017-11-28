/*
--------------------------------------------------------------------------------------------------------
Laboratory : 06 Number of Day
File       : date.h
Author(s)  : Jonathan Zaehringer, Florian Schaufelberger
Date       : 20.11.2017

Aim        : Header of date.cpp, define the enum class Month
                used in date.cpp to get days of month and month name

Comment(s) : Move algorithm function from calendar.cpp to improve coherence

                getFirstDayOfMonth, getDaysInMonth,
                getNumberOfDaysInMonth, getDayOfWeek,
                isLeap.

             All functions wasn't restrictive on the type of arguments. Using it with
                negative int is your own risk.

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0
--------------------------------------------------------------------------------------------------------
*/

#ifndef DATE_HEADER
#define DATE_HEADER

#include <string>

enum class Month {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE,
    JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

// --------------------
// Algorithm functions
// --------------------
std::string getMonthName(int month);
int getFirstDayOfMonth(int firstDayOfYear, int month, int year);
int getDaysInMonth(int month, int year);
int getNumberOfDaysInMonth(int month, int year);
int getDayOfWeek(int year, int month = 1, int day = 1);

bool isLeap(int year);
bool isValidGregorianDate(int day, int month, int year);
bool isDateBiggerThen(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);

int nbDaysByMonth(int startDay, int endDay, int month, int startMonth, int endMonth, int year);
int nbDaysBetweenDates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear);

#endif
