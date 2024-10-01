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


/*
std::find() function
is used to look for value. If not found, std::find returns 
cont.end().

typename T::iterator
T::iterator is a dependent type because the actual type of 
T::iterator depends on the template parameter T. The C++ 
compiler doesn't automatically know if T::iterator is a type 
or something else (like a static member, for example), so you 
need to explicitly tell it that T::iterator is a type by 
prefixing it with typename.
*/
template <typename T>
typename T::iterator easyfind(T& cont, int value)
{
	typename T::iterator it;
    
    it = std::find(cont.begin(), cont.end(), value);
	if (it == cont.end())
		throw NotFoundException();
	return it;
}