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
    /*
    checking if file is a directory:

    fileStat: An instance of struct stat that will hold the information about 
        the file specified by the path inputFile.

    stat Function:
        - Retrieves information about the file or directory specified by the path 
        inputFile and stores it in the fileStat structure.
        - inputFile.c_str(): Converts the C++ string (std::string) into a C-style string 
        (const char*), which is required by stat.
        - &fileStat: A pointer to the fileStat structure where the file information will 
        be stored.
        - Returns:
        0: Indicates success, meaning the file/directory exists and stat successfully 
        retrieved its information.
        -1: Indicates failure, meaning the file/directory does not exist or cannot be 
        accessed. This might occur due to insufficient permissions or an invalid path.

    fileStat.st_mode: A field in struct stat that contains the file's mode, including 
    information about its type and permissions.

    S_ISDIR(fileStat.st_mode): 
        - A macro that checks if the mode (st_mode) indicates that the path is a directory.
        - Returns:
            true if the path refers to a directory.
            false otherwise (e.g., if it’s a regular file).
    */
    struct stat fileStat; 
    if (stat(inputFile.c_str(), &fileStat) == 0) 
    {
        if (S_ISDIR(fileStat.st_mode)) 
        {
            std::cerr << "Error: the specified input is a directory, not a file." << std::endl;
            return;
        }
    } else 
    {
        std::cerr << "Error: could not stat the file." << std::endl;
        return;
    }

    // checking if file can be open
    std::ifstream file(inputFile);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // reading headerline

    // checking if header line is in a proper way written
    std::regex pattern(R"(^\s*date\s*\|\s*value\s*$)"); // Regular expression pattern for "date | value"
    
    if (!std::regex_match(line, pattern)) 
    {
        // If the line does not match the expected pattern
        std::cerr << "Error: invalid headerline format => " << line << std::endl;
        // return;
    }

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

        // Check for any trailing non-whitespace characters in the stream
        // this will make sure that case "3bsdbsdb" is not gonna be handled as a "3",
        // but as an incorrect value
        std::string remaining;
        if (ss >> remaining) 
        {
            // If there's anything left in the stream, it's an error
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // trimming spaces around date
        dateStr = dateStr.substr(dateStr.find_first_not_of(" \t")); 
        dateStr = dateStr.substr(0, dateStr.find_last_not_of(" \t") + 1); 

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
