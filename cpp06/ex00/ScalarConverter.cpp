#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input(""), _value(0.0) {}

ScalarConverter::ScalarConverter(const std::string &input) : _input(input), _value(0.0) {
    try {
        detectAndConvert();
        printResults();
    } catch (const ConversionException &e) {
        std::cerr << e.what() << std::endl;
    }
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
    if (this != &src) {
        this->_input = src._input;
        this->_value = src._value;
    }
    return *this;
}

// Function to detect input type and perform conversion
void ScalarConverter::detectAndConvert() {
    // Check for special cases like "nan", "+inf", etc.
    if (isSpecialCase()) {
        return;
    }

    // Try to convert the input to a double (this covers most cases)
    try {
        _value = std::stod(_input);
    } catch (const std::invalid_argument &) {
        throw ConversionException();
    } catch (const std::out_of_range &) {
        throw ConversionException();
    }
}

// Check if the input is a special case (nan, inf)
bool ScalarConverter::isSpecialCase() const {
    if (_input == "nan" || _input == "nanf" ||
        _input == "+inf" || _input == "-inf" ||
        _input == "+inff" || _input == "-inff") {
        handleSpecialCase();
        return true;
    }
    return false;
}

// Handle special cases (nan, inf)
void ScalarConverter::handleSpecialCase() const {
    if (_input == "nan" || _input == "nanf") {
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
    } else if (_input == "+inf" || _input == "+inff") {
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
    } else if (_input == "-inf" || _input == "-inff") {
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
    }
}

// Function to print conversion results
void ScalarConverter::printResults() const {
    printChar();
    printInt();
    printFloat();
    printDouble();
}

// Print char conversion
void ScalarConverter::printChar() const {
    if (std::isnan(_value) || std::isinf(_value) || _value < 0 || _value > 127) {
        std::cout << "char: impossible\n";
    } else if (!std::isprint(static_cast<char>(_value))) {
        std::cout << "char: Non displayable\n";
    } else {
        std::cout << "char: '" << static_cast<char>(_value) << "'\n";
    }
}

// Print int conversion
void ScalarConverter::printInt() const {
    if (std::isnan(_value) || std::isinf(_value) || _value < std::numeric_limits<int>::min() || _value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible\n";
    } else {
        std::cout << "int: " << static_cast<int>(_value) << "\n";
    }
}

// Print float conversion
void ScalarConverter::printFloat() const {
    std::cout << std::fixed << std::showpoint;
    if (std::isnan(_value)) {
        std::cout << "float: nanf\n";
    } else if (std::isinf(_value)) {
        std::cout << "float: " << (_value > 0 ? "+inff" : "-inff") << "\n";
    } else {
        std::cout << "float: " << static_cast<float>(_value) << "f\n";
    }
}

// Print double conversion
void ScalarConverter::printDouble() const {
    std::cout << std::fixed << std::showpoint;
    if (std::isnan(_value)) {
        std::cout << "double: nan\n";
    } else if (std::isinf(_value)) {
        std::cout << "double: " << (_value > 0 ? "+inf" : "-inf") << "\n";
    } else {
        std::cout << "double: " << _value << "\n";
    }
}
