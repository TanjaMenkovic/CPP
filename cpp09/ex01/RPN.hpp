#pragma once

#include <iostream>
#include <stack>
#include <cctype>

class RPN
{
    private:
	    std::stack<double> numbers;
    public:
	    RPN();
	    RPN(std::stack<double> number);
	    RPN(const RPN &var);
	    ~RPN();
	    RPN &operator=(const RPN &var);
	    
        void rpn(std::string input);	

        class InvalidInput : public std::exception
	    {
		    public:
                virtual const char* what() const throw();
	    };

        class EmptyInput : public std::exception
	    {
		    public:
                virtual const char* what() const throw();
	    };

        class DivisionZero : public std::exception
	    {
		    public:
                virtual const char* what() const throw();
	    };

        class InvalidChar : public std::exception
	    {
		    public:
                virtual const char* what() const throw();
	    };
};