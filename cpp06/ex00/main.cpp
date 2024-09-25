#include "ScalarConverter.hpp"

int main() {
    ScalarConverter defaultConverter;
    ScalarConverter converter1("42.0f");
    ScalarConverter converter2(converter1);
    ScalarConverter converter3;
    converter3 = converter1;

    return 0;
}