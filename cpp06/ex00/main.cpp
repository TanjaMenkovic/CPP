#include "ScalarConverter.hpp"

int main() {
    ScalarConverter defaultConverter;
    ScalarConverter converter1("42.0f");
    ScalarConverter converter2("888");
    ScalarConverter converter3("rbeberbe");
    ScalarConverter converter4("9");
    ScalarConverter converter5("999999999999");
    ScalarConverter converter6("98");
    ScalarConverter converter7("9999999999999999999999.9999999999");
    ScalarConverter converter8("-8889");

    std::cout << "\nConverting 42.0f:\n";
    converter1.convert();
    std::cout << "\nConverting 888:\n";
    converter2.convert();
    std::cout << "\nConverting rbeberbe:\n";
    converter3.convert();
    std::cout << "\nConverting 9:\n";
    converter4.convert();
    std::cout << "\nConverting 999999999999:\n";
    converter5.convert();
    std::cout << "\nConverting 98:\n";
    converter6.convert();
    std::cout << "\nConverting 9999999999999999999999.9999999999:\n";
    converter7.convert();
    std::cout << "\nConverting -8889:\n";
    converter8.convert();

    return 0;
}
