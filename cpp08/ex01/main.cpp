#include "Span.hpp"

int main()
{
    Span sp = Span(50);

    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
        std::cout << "Print: " << std::endl;
        sp.printSpan();

        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "Ading range (6,9):\n";
        sp.addRange(6, 9);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
        std::cout << "Print: " << std::endl;
        sp.printSpan();

        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "Ading range (-7, 3):\n";
        sp.addRange(-7, 13);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
        std::cout << "Print: " << std::endl;
        sp.printSpan();

        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "Ading range (77,34):\n";
        sp.addRange(77, 34);
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
        std::cout << "Print: " << std::endl;
        sp.printSpan();

        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}