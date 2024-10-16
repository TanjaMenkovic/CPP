#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange(void) {}

// Constructor with CSV database path
BitcoinExchange::BitcoinExchange(const std::string db_path)
{
    loadPrices(db_path);
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    this->btcPrices = src.btcPrices;
}

// Assignment operator
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
    {
        this->btcPrices = src.btcPrices;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange(void) {}

// Load Bitcoin prices from a CSV file (date, price)
void BitcoinExchange::loadPrices(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw CantReadDataFileException();
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        double price;

        if (std::getline(ss, date, ',') && (ss >> price))
        {
            // Ensure valid date parsing
            Date parsedDate;
            if (!parseDate(date, parsedDate) || !checkDate(parsedDate))
            {
                std::cerr << "Invalid date format in data file: " << date << std::endl;
                continue ;
            }

            this->btcPrices[date] = price;
        }
    }
    file.close();
}

// Find the closest date that is <= the given date
std::string BitcoinExchange::findClosestDate(const std::string &date) const
{
    auto it = this->btcPrices.lower_bound(date);
    if (it == this->btcPrices.end() || it->first != date)
    {
        if (it == this->btcPrices.begin())
            return ""; // No valid earlier date

        --it; // Step to previous date
    }
    return it->first;
}

// Process input file to calculate Bitcoin values based on date and input value
void BitcoinExchange::processInputFile(const std::string &inputFile)
{
    std::ifstream file(inputFile);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string dateStr, valueStr;
        double value;

        if (!std::getline(ss, dateStr, '|') || !(ss >> value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        dateStr = dateStr.substr(0, dateStr.find_last_not_of(" \t") + 1); // Trim dateStr

        // Parse the date string
        Date date;
        if (!parseDate(dateStr, date) || !checkDate(date))
        {
            std::cerr << "Error: invalid date => " << dateStr << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue ;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue ;
        }

        // Find closest date in Bitcoin prices
        std::string closestDate = findClosestDate(dateStr);
        if (closestDate.empty())
        {
            std::cerr << "Error: no valid date found in database." << std::endl;
            continue ;
        }

        // Perform the calculation
        double btcPrice = this->btcPrices[closestDate];
        double result = value * btcPrice;
        std::cout << dateStr << " => " << value << " = " << std::setprecision(2) << std::fixed << result << std::endl;
    }
    file.close();
}

// Exception message for CantReadDataFileException
const char *BitcoinExchange::CantReadDataFileException::what(void) const throw()
{
    return "Error: Can't read data file.";
}
