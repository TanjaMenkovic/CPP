#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <sstream>
#include <cstdlib>  // for atoi

typedef struct Date
{
    int dd;
    int mm;
    int yyyy;
}   Date;

bool isDigits(const std::string& str);
bool parseDate(const std::string& dateStr, Date &date);
bool checkDate(Date date);
