#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
    // Check if the program is called with exactly one argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    // Create a BitcoinExchange instance
    BitcoinExchange btcExchange;

    try {
        // Load Bitcoin prices from the provided CSV file (e.g., data.csv)
        btcExchange.loadPrices("data.csv");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    // Process the input file (provided as argument) using the processInputFile method
    btcExchange.processInputFile(argv[1]);

    return 0;
}
