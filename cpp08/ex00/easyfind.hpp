#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <exception>
#include <vector>

class NotFoundException: public std::exception
{
	public:
			virtual const char *what() const throw()
			{
				return ("Target integer not found in container");
			}
};

template <typename T>
typename T::iterator easyfind(T& cont, int value)
{
	typename T::iterator it;
    
    it = std::find(cont.begin(), cont.end(), value);
	if (it == cont.end())
		throw NotFoundException();
	return it;
}