/*
--------------------------------------------------------------------------------------------------------
Laboratory : 06 Number of Day
File       : date.cpp
Author(s)  : Jonathan Zaehringer, Florian Schaufelberger
Date       : 20.11.2017

Aim        : Library to manipulate date in any format, The validation of a date
                is based on Gregorian calendar.
                
Comment(s) : Move algorithm function from calendar.cpp to improve coherence

                getFirstDayOfMonth, getDaysInMonth,
                getNumberOfDaysInMonth, getDayOfWeek,
                isLeap.

             All functions wasn't restrictive on the type of arguments. Using it with
                negative int is your own risk.

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or g++ (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0
--------------------------------------------------------------------------------------------------------
*/

#include <cmath>
#include <string>

#include "misc.h"
#include "date.h"

// -------------------------------
// Algorithm functions
// -------------------------------

bool isValidGregorianDate (int day, int month, int year) {
    const int MIN_DAY = 1,
              MIN_MONTH = 1,
              MAX_MONTH = 12;

    unless (year >= 0) {
        return false;
    }

    unless (isBetween(month, MIN_MONTH, MAX_MONTH)) {
        return false;
    }

    unless (isBetween(day, MIN_DAY, getNumberOfDaysInMonth(month, year))) {
        return false;
    }

    return true;
}

std::string getMonthName(int month) {
    switch (Month(month)) {
        case Month::JANUARY   : return "Janvier";
        case Month::FEBRUARY  : return "Fevrier";
        case Month::MARCH     : return "Mars";
        case Month::APRIL     : return "Avril";
        case Month::MAY       : return "Mai";
        case Month::JUNE      : return "Juin";
        case Month::JULY      : return "Juillet";
        case Month::AUGUST    : return "Aout";
        case Month::SEPTEMBER : return "Septembre";
        case Month::OCTOBER   : return "Octobre";
        case Month::NOVEMBER  : return "Novembre";
        case Month::DECEMBER  : return "Decembre";
        default               : return "Invalid value";
    }
}

int getDayOfWeek(int year, int month, int day) {
    // month and day set to 1 by def.
    // This function is mainly used to get the day of 1st Jan from a given year
    // return an index for the first day of a given month.
    // index equals 1 for monday, 2 for thuesday,... until 7 for sunday
    // Based on the disparate variation of the Gauss's algorithm
    // src : https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
    
    if (month < 3) {        // if month is jan or feb
        year -= 1;          // we work with the previous year
    }

    int c = year / 100;     // two last digits
    int y = year - c * 100; // two first digits
    int result;

    month = (month + 9) % 12 + 1; // shift the month (Mars => 1, ..., Feb => 12)

    // translation of the mathematic formula (gives Sunday => 0, ..., Saturday => 6)
    result = (day + (int)floor(2.6 * month - 0.2) - 2 * c + y + y/4 + c/4 + 7)% 7;
    
    // shift previous result (to have Monday => 1, ..., Sunday => 7) 
    result = (result + 6) % 7 + 1;

    return result;
}

int getFirstDayOfMonth(int firstDayOfYear, int month, int year) {
    const int SHIFT_LOW_MONTH  = 30 % 7;
    const int SHIFT_FULL_MONTH = 31 % 7;

    int result = firstDayOfYear;

    switch (Month(month)) {
        case Month::DECEMBER  : result += SHIFT_LOW_MONTH; 
        case Month::NOVEMBER  : result += SHIFT_FULL_MONTH; 
        case Month::OCTOBER   : result += SHIFT_LOW_MONTH; 
        case Month::SEPTEMBER : result += SHIFT_FULL_MONTH;
        case Month::AUGUST    : result += SHIFT_FULL_MONTH;
        case Month::JULY      : result += SHIFT_LOW_MONTH;
        case Month::JUNE      : result += SHIFT_FULL_MONTH;
        case Month::MAY       : result += SHIFT_LOW_MONTH;
        case Month::APRIL     : result += SHIFT_FULL_MONTH;
        case Month::MARCH     : result += isLeap(year); // shift by 1 if leap, 0 otherwise
        case Month::FEBRUARY  : return (result += SHIFT_LOW_MONTH) %  7 + 1;
        default               : return result;
    }
}
 


bool isLeap(int year) {
    // return if year is leap
    //      if divisible by 400 or divisible by 4 but not by 100
    return !(year % 400) || (!(year % 4) && year % 100);
}

int getNumberOfDaysInMonth(int month, int year) {
    switch (Month(month)) {
        case Month::FEBRUARY  : return 28 + isLeap(year);
        case Month::APRIL     : 
        case Month::JUNE      :
        case Month::SEPTEMBER :
        case Month::NOVEMBER  : return 30;
        default               : return 31;
    }
}
bool isDateBiggerThen(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {
    return startYear < endYear || (startYear == endYear && (startMonth < endMonth || (startMonth == endMonth && startDay <= endDay)));
}

int nbDaysByMonth(int startDay, int endDay, int month, int startMonth, int endMonth, int year, int startYear, int endYear) {
    // if the startmonth is different than the endMonth, we will just set endmonth as defaut number of days as the month have.

    int minDay = 1,
        maxDay = endDay;

    if (year == startYear && month == startMonth) {
        minDay = startDay;
    }

    unless (year == endYear && month == endMonth) {
        maxDay = getNumberOfDaysInMonth(month, year);
    }

    // we add + 1 otherwise we will miss 1 day in the subtraction.
    return maxDay - minDay + 1;
}

int nbDaysBetweenDates(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {
    // we will count how many days there is in the starter month and then we will just add the number of days
    // of the next month until we arrive at the endYear and the endmonth were we will count again how many days
    // there is in this final month.
    // if we are not in the starter year or the final year, we will count 365 or 366 day by year, 
    //  366 days is when the year is leap.

    unless (isDateBiggerThen(startDay, startMonth, startYear, endDay, endMonth, endYear)) {
        return -1;
    }

    const int NB_DAYS_PER_YEAR = 365,
              MIN_MONTH        = 1,
              MAX_MONTH        = 12;

    int totalDays = 0;
    
    for(int year = startYear; year <= endYear; ++year){
        int month    = MIN_MONTH,
            maxMonth = MAX_MONTH;

        if(year == startYear) {
            month = startMonth;
        }

        if(year == endYear) {
            maxMonth = endMonth;
        }

        unless (year == startYear || year == endYear) {
            totalDays += NB_DAYS_PER_YEAR + isLeap(year);
        } else {
            for(; month <= maxMonth; ++month) {
                unless (month == startMonth || month == endMonth){
                    totalDays += getNumberOfDaysInMonth(month, year);
                } else {
                    totalDays += nbDaysByMonth(startDay, endDay, month, startMonth, endMonth, year, startYear, endYear);
                }
            }
        }
    }

    return totalDays;
}
