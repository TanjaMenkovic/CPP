#pragma once

#include <string> // std::string type; std::string::c_str(), std::string::compare(), and std::string::find()
#include <iostream> // std::cout; printResults(), printChar(), printInt(), printFloat(), and printDouble() 
#include <limits> // std::numeric_limits<int>::min() and std::numeric_limits<int>::max()
#include <cstdlib> // std::stod()
#include <stdexcept> // std::invalid_argument and std::out_of_range
#include <cctype> // std::isprint()
#include <cmath> // std::isnan() and std::isinf()
#include <sstream>   // For std::stringstream
#include <iomanip>   // For std::setprecision

class ScalarConverter {
private:
    std::string _input;
    double _value;

    void detectAndConvert();
    void printResults() const;

    bool isSpecialCase() const;
    void handleSpecialCase() const;

    void printChar() const;
    void printInt() const;
    void printFloat() const;
    void printDouble() const;

public:
    ScalarConverter();                              
    ScalarConverter(const std::string &input);      
    ScalarConverter(const ScalarConverter &src);    
    ~ScalarConverter();

    ScalarConverter &operator=(const ScalarConverter &src);

    void convert();

    class ConversionException : public std::exception 
    {
        public:
                virtual const char* what() const throw();
    };
};
