#pragma once

#include <iostream>
#include <stack>
#include <cctype>


/*
Why I used stack?

A std::stack is ideal for this RPN evaluator because:
1. RPN relies heavily on the LIFO order for operand handling.
2. It simplifies the process of managing operands, ensuring efficient operations 
	(O(1) complexity).
3. It fits naturally with the flow of RPN evaluation.
4. The stack provides a clear and efficient way to manage errors (like insufficient 
	operands or division by zero).
Thus, std::stack makes your RPN class implementation cleaner, more efficient, and easier to reason about.
*/
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