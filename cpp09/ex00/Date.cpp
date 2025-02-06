#include "Date.hpp"

bool isDigits(const std::string& str) 
{
    for (char c : str)
    {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

// Function to parse the string "YYYY-MM-DD" into a Date structure
bool parseDate(const std::string& dateStr, Date &date) 
{
    if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-') // Ensure that the format is correct (YYYY-MM-DD)
        return false;

    // Extract the year, month, and day parts from the string
    std::string yearPart = dateStr.substr(0, 4);
    std::string monthPart = dateStr.substr(5, 2);
    std::string dayPart = dateStr.substr(8, 2);

    // Validate that all extracted parts are numeric
    if (!isDigits(yearPart) || !isDigits(monthPart) || !isDigits(dayPart))
        return false;

    try 
    {
        date.yyyy = std::stoi(yearPart);
        date.mm = std::stoi(monthPart);
        date.dd = std::stoi(dayPart);
    } 
    catch (std::invalid_argument const& e) 
    {
        return false;
    }
    catch (std::out_of_range const& e) 
    {
        return false;
    }

    return true;
}

static bool isLeapYear(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // A leap year is divisible by 4, but not by 100 unless it's divisible by 400
}

bool checkDate(Date date)
{
    // Check the validity of the year, month, and day
    if (date.yyyy < 1 || date.mm < 1 || date.mm > 12 || date.dd < 1) 
        return false;

    // Days in each month (index 0 is a placeholder to align month numbers with index)
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for February in a leap year
    if (date.mm == 2 && isLeapYear(date.yyyy)) 
        daysInMonth[2] = 29;

    // Check if the day is valid for the given month
    if (date.dd > daysInMonth[date.mm])
        return false;

    return true;
}
