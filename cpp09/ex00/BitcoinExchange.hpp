#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <alhorithm>
#include <exception>
#include <sstream>
#include <cstdlib>  // for atoi
#include <iomanip> // for std::setprecision

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
        std::string findClosestDate(const std::string& date); 
        void        processInputFile(const std::string& inputFile);

        class CantReadDataFileException: public std::exception 
        {
	        public:
		        virtual const char* what(void) const throw();
	    };

};