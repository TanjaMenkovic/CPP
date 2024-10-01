#include "Iter.hpp"

// Example function to print an integer
void printInt(int& n) 
{
    std::cout << n << " ";
}

// Example function to increment an integer
void incrementInt(int& n) 
{
    ++n;
}

// Example function to print a string
void printString(std::string& str) 
{
    std::cout << str << " ";
}

// Example function to convert a string to uppercase
void toUpperCase(std::string& str) 
{
    for (char& c : str) 
    {
        c = std::toupper(c);
    }
}

int main() 
{
    // Testing with an array of integers
    std::cout << "\n***Testing with an array of integers*** \n\n";

    int intArr[] = {1, 2, 3, 4, 5};
    size_t intArrLen = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "\nOriginal integers: \n";
    ::iter(intArr, intArrLen, printInt);
    std::cout << std::endl;

    std::cout << "\n...Incrementing integers..." << std::endl;
    ::iter(intArr, intArrLen, incrementInt);

    std::cout << "Incremented integers: \n";
    ::iter(intArr, intArrLen, printInt);
    std::cout << std::endl;

    // Testing with an array of strings
    std::cout << "\n***Testing with an array of strings*** \n\n";

    std::string strArr[] = {"Cats", "are", "THE", "BEST", "animals", "ever"};
    size_t strArrLen = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "\nOriginal strings: \n";
    ::iter(strArr, strArrLen, printString);
    std::cout << std::endl;

    std::cout << "\n...Converting strings to uppercase..." << std::endl;
    ::iter(strArr, strArrLen, toUpperCase);

    std::cout << "Uppercase strings: \n";
    ::iter(strArr, strArrLen, printString);
    std::cout << std::endl;

    return 0;
}