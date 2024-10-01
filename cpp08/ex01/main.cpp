#include "Span.hpp"

int main()
{
    Span sp = Span(50);
    Span sp1 = Span(30000);

    try
    {
        std::cout << "\nCreating span with numbers: 6, 3, 17, 9, 11:\n";
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    
        std::cout << "Print: " << std::endl;
        sp.printSpan();
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;

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
        std::cout << "Print: " << std::endl;
        sp.printSpan();
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;

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
        std::cout << "Print: " << std::endl;
        sp.printSpan();
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;

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
        std::cout << "Print: " << std::endl;
        sp.printSpan();
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;

        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "Creating new span with range (1, 10000):\n";
        sp1.addRange(1, 10000);
        // std::cout << "Print: " << std::endl;
        // sp1.printSpan();
        std::cout << "Shortest: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp1.longestSpan() << std::endl;

        std::cout << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}