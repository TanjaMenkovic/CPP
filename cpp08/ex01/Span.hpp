#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>
#include <limits>

class Span
{
    private:
        unsigned int size;
        std::vector<int> storage;
        Span();

    public:
        Span(unsigned int N);
        ~Span();
        Span(const Span& src);
        Span& operator=(const Span& src);

        void addNumber(int num);
        void addRange(int start, int end);
        int shortestSpan();
        int longestSpan();

        void printSpan();

        class NotEnoughSpaceException: public std::exception
        {
	        public:
	    		virtual const char *what() const throw()
	    		{
	    			return ("Storage is already full!!\n");
	    		}
        };

        class NoSpanException: public std::exception
        {
	        public:
	    		virtual const char *what() const throw()
	    		{
	    			return ("No span can be found!!\n");
	    		}
        };

        class NotRangeException: public std::exception
        {
	        public:
	    		virtual const char *what() const throw()
	    		{
	    			return ("Can't define a range based on these values!!\n");
	    		}
        };
};