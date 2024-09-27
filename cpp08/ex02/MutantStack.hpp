#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        typedef std::stack<T> stack;
	    typedef typename stack::container_type container;
	    typedef typename container::iterator iterator;

        MutantStack(): stack() {}

        MutantStack(const MutantStack& src): stack(src) {}

        MutantStack& operator=(const MutantStack& src)
        {
            if (*this != src)
                *this = src;
            return *this;
        }

        ~MutantStack() {}

        iterator begin()
	    {
		    return (stack::c.begin());
	    }

	    iterator end()
	    {
		    return (stack::c.end());
	    }
};