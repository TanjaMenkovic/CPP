#include "Functions.hpp"

int main() {
    // Testing with integers
    int x = 10, y = 20;
    std::cout << "Original x: " << x << ", y: " << y << std::endl;
    ::swap(x, y);
    std::cout << "Swapped x: " << x << ", y: " << y << std::endl;
    std::cout << "Min(x, y): " << ::min(x, y) << std::endl;
    std::cout << "Max(x, y): " << ::max(x, y) << std::endl;

    // Testing with doubles
    double a = 1.1, b = 2.2;
    std::cout << "\nOriginal a: " << a << ", b: " << b << std::endl;
    ::swap(a, b);
    std::cout << "Swapped a: " << a << ", b: " << b << std::endl;
    std::cout << "Min(a, b): " << ::min(a, b) << std::endl;
    std::cout << "Max(a, b): " << ::max(a, b) << std::endl;

    // Testing with characters
    char c1 = 'A', c2 = 'B';
    std::cout << "\nOriginal c1: " << c1 << ", c2: " << c2 << std::endl;
    ::swap(c1, c2);
    std::cout << "Swapped c1: " << c1 << ", c2: " << c2 << std::endl;
    std::cout << "Min(c1, c2): " << ::min(c1, c2) << std::endl;
    std::cout << "Max(c1, c2): " << ::max(c1, c2) << std::endl;

    // Testing with strings
    std::string s1 = "Hello", s2 = "World";
    std::cout << "\nOriginal s1: " << s1 << ", s2: " << s2 << std::endl;
    ::swap(s1, s2);
    std::cout << "Swapped s1: " << s1 << ", s2: " << s2 << std::endl;
    std::cout << "Min(s1, s2): " << ::min(s1, s2) << std::endl;
    std::cout << "Max(s1, s2): " << ::max(s1, s2) << std::endl;

    return 0;
}