#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(std::stack<double> number) : numbers(number) {}

RPN::RPN(const RPN &var)
{
	*this = var;
}

RPN &RPN::operator=(const RPN &var)
{
	this->numbers = var.numbers;
	return (*this);
}

void RPN::rpn(std::string input)
{
    char c;
    int number;
    double a;
    double b;

    if (input.empty())
        throw RPN::EmptyInput();
    else if (input.size() <= 2)
        throw RPN::InvalidInput();
    else
	{
		for (size_t i = 0; i < input.size(); i++)
		{
        	c = input[i];

			if (isspace(c))
				continue ; // skip whitespace
        	else if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
            	throw RPN::InvalidChar();
			else if (isdigit(c))
			{
				number = c - '0';
				numbers.push(number); // Adds an element to the top of the stack.
			}
			else if (c == '+' && numbers.size() >= 2)
			{
				b = numbers.top(); // Returns (but does not remove) the top element of the stack.
				numbers.pop(); // Removes the top element of the stack.
				a = numbers.top();
				numbers.pop();

				numbers.push(a + b);
			}
			else if (c == '-' && numbers.size() >= 2)
			{
				b = numbers.top();
				numbers.pop();
				a = numbers.top();
				numbers.pop();

				numbers.push(a - b);
			}
			else if (c == '*' && numbers.size() >= 2)
			{
				b = numbers.top();
				numbers.pop();
				a = numbers.top();
				numbers.pop();

				numbers.push(a * b);
			}
			else if (c == '/' && numbers.size() >= 2)
			{
				b = numbers.top();
				numbers.pop();
				a = numbers.top();
				numbers.pop();

            	if (b == 0)
                	throw RPN::DivisionZero();
				numbers.push(a / b);
			}
			else
				throw RPN::InvalidInput();
		}
	}
	
	if (numbers.size() == 1)
	{
		std::cout << "Result: " << numbers.top() << std::endl;
        numbers.pop();
	}
	else
		throw RPN::InvalidInput();
}

const char*	RPN::InvalidInput::what() const throw()
{
    return ("Error: Invalid input!");
}

const char*	RPN::EmptyInput::what() const throw()
{
    return ("Error: Empty input!");
}

const char*	RPN::DivisionZero::what() const throw()
{
    return ("Error: Division with zero!");
}

const char*	RPN::InvalidChar::what() const throw()
{
    return ("Error: Invalid character!");
}