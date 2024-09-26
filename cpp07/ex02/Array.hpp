#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
		T*              arr;
		unsigned int    sizeA;

	public:
		Array(): arr(nullptr), sizeA(0) {}

		Array(unsigned int n): sizeA(n)
		{
			arr = new T[n];
		}

		Array(const Array& src): sizeA(src.sizeA)
		{
			arr  = new T[sizeA];
			arr = NULL;
            *this = src;
		}

		Array& operator=(const Array& src)
		{
            if (arr != NULL)
                delete[] arr;
            if (src.sizeA != NULL)
            {
			    sizeA = src.sizeA;
			    arr  = new T[sizeA];
			    for (unsigned int i = 0; i < sizeA; i++)
			    {
				    arr[i] = src.arr[i];
			    }
            }
			return *this;
		}

		~Array()
		{
            if (arr != NULL)
			    delete[] arr;
		}

		T& operator[](const unsigned int index)
		{
			if (index >= sizeA || index < 0)
				throw BoundsException();

            if (arr == NULL)
                throw InvalidException();

			return arr[index];
		}

		unsigned int size() const
		{
			return sizeA;
		}

		class BoundsException : public std::exception
	    {
		    const  char* what() const noexcept
		    {
		    	return "The array is out of bounds";
		    }
	    };

        class InvalidException : public std::exception
	    {
		    const  char* what() const noexcept
		    {
		    	return "Invalid array";
		    }
	    };
};