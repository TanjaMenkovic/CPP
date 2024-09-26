#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input(""), _value(0.0) {}

ScalarConverter::ScalarConverter(const std::string &input) : _input(input), _value(0.0) {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) 
{
    *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) 
{
    if (this != &src) 
    {
        this->_input = src._input;
        this->_value = src._value;
    }
    return *this;
}

// Check if the input is a special case (nan, inf)
bool ScalarConverter::isSpecialCase() const 
{
    if (_input == "nan" || _input == "nanf" ||
        _input == "+inf" || _input == "-inf" ||
        _input == "+inff" || _input == "-inff") 
    {
        handleSpecialCase();
        return true;
    }
    return false;
}

// Handle special cases (nan, inf)
void ScalarConverter::handleSpecialCase() const 
{
    if (_input == "nan" || _input == "nanf") 
    {
        std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
    } 
    else if (_input == "+inf" || _input == "+inff") 
    {
        std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
    } 
    else if (_input == "-inf" || _input == "-inff") 
    {
        std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
    }
}

// Print char conversion
void ScalarConverter::printChar() const 
{
    if (std::isnan(_value) || std::isinf(_value) || _value < 0 || _value > 127) 
    {
        std::cout << "char: impossible\n";
    } 
    else if (!std::isprint(static_cast<char>(_value))) 
    {
        std::cout << "char: Non displayable\n";
    } 
    else 
    {
        std::cout << "char: '" << static_cast<char>(_value) << "'\n";
    }
}

// Print int conversion
void ScalarConverter::printInt() const {
    if (std::isnan(_value) || std::isinf(_value) || 
        _value < std::numeric_limits<int>::min() ||
        _value > std::numeric_limits<int>::max()) 
    {
        std::cout << "int: impossible\n";
    } 
    else 
    {
        std::cout << "int: " << static_cast<int>(_value) << "\n";
    }
}

// Print float conversion
void ScalarConverter::printFloat() const 
{
    std::cout << std::fixed << std::showpoint;

    if (std::isnan(_value)) 
    {
        std::cout << "float: nanf\n";
    } 
    else if (std::isinf(_value)) 
    {
        std::cout << "float: " << (_value > 0 ? "+inff" : "-inff") << "\n";
    } 
    else 
    {
        try 
        {
            // Convert to float and back to check representability
            float testValue = static_cast<float>(_value);
            if (testValue != _value) // if it's out of limits
                throw std::overflow_error("Value not representable as float");

            std::cout << "float: " << testValue << "f\n";
        } 
        catch (...) 
        {
            std::cout << "float: impossible\n";
        }
    }
}

// print double conversion
void ScalarConverter::printDouble() const 
{
    std::cout << std::fixed << std::showpoint;

    if (std::isnan(_value)) 
    {
        std::cout << "double: nan\n";
        return ;
    } 
    else if (std::isinf(_value)) 
    {
        std::cout << "double: " << (_value > 0 ? "+inf" : "-inf") << "\n";
        return ;
    }
    try 
    {
        std::string inputNew = _input;

        // Check if the input string ends with 'f' and remove it
        if (!inputNew.empty() && inputNew.back() == 'f') 
        {
            inputNew.pop_back(); // Remove the last character
        }

        // Convert to double
        double valueNew = std::stod(inputNew);

        // Convert valueNew to string with precision
        std::stringstream ss;
        ss << std::setprecision(15) << valueNew;  // 15 digits of precision for double
        std::string doubleStr = ss.str();

        // Check if the formatted string matches the modified input
        // Remove trailing zeros for comparison
        doubleStr.erase(doubleStr.find_last_not_of('0') + 1, std::string::npos);
        if (doubleStr.back() == '.') {
            doubleStr.pop_back(); // Remove the decimal point if it exists
        }

        // Also trim the modified input
        inputNew.erase(inputNew.find_last_not_of('0') + 1, std::string::npos);
        if (inputNew.back() == '.') {
            inputNew.pop_back(); // Remove the decimal point if it exists
        }

        // Compare the formatted doubleStr with the modified input
        if (doubleStr != inputNew) // if it's out of limits
        {
            throw std::overflow_error("Value not representable as double");
        }

        std::cout << "double: " << valueNew << "\n";
    } 
    catch (const std::invalid_argument &) 
    {
        std::cout << "double: impossible\n";
    } 
    catch (const std::out_of_range &) 
    {
        std::cout << "double: impossible\n";
    } 
    catch (...) 
    {
        std::cout << "double: impossible\n";
    }
}

void ScalarConverter::detectAndConvert() 
{
    if (isSpecialCase()) // Check for special cases like "nan", "+inf", etc.
    {
        return ;
    }

    // Try to convert the input to a double (this covers most cases)
    try 
    {
        _value = std::stod(_input);
    } 
    catch (const std::invalid_argument &) 
    {
        throw ConversionException();
    } 
    catch (const std::out_of_range &) 
    {
        throw ConversionException();
    }
}

// Function to print conversion results
void ScalarConverter::printResults() const 
{
    printChar();
    printInt();
    printFloat();
    printDouble();
}

void ScalarConverter::convert()
{
    try 
    {
        detectAndConvert();
        printResults();
    } 
    catch (const ConversionException &e) 
    {
        std::cerr << e.what() << std::endl;
    }
}

const char*	ScalarConverter::ConversionException::what() const throw()
{
	return ("Conversion error!");
}