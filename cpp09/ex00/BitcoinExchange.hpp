#pragma once

#include <string>
#include <iostream>
#include <fstream>
//#include <alhorithm>
#include <map>
#include <exception>
#include <sstream>
#include <cstdlib>  // for atoi
#include <iomanip> // for std::setprecision
#include <sys/stat.h> // for checking is it a directory
#include <regex> // checking pattern

#include "Date.hpp"

class BitcoinExchange
{
    private:
        std::map<std::string, double> btcPrices; // Map of date (YYYY-MM-DD) to Bitcoin price

    public:
        BitcoinExchange(void);
	    BitcoinExchange(const std::string db_path);
	    BitcoinExchange(const BitcoinExchange &src);
	    ~BitcoinExchange(void);
	    BitcoinExchange	&operator =(const BitcoinExchange &src);

        void        loadPrices(const std::string& filename); 
        std::string findClosestDate(const std::string& date) const; 
        void        processInputFile(const std::string& inputFile);

        class CantReadDataFileException: public std::exception 
        {
	        public:
		        virtual const char* what(void) const throw();
	    };

};