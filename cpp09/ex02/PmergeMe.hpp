#pragma once

#include <iostream>
#include <exception>
#include <cctype>
#include <cstdlib>  // For std::strtol (long int)

#include <algorithm>
#include <vector>
#include <list>


/*
template class will have everything universal for any type of container and then subclasses
will be separately vectors and lists

class S - sequence
class P - pairs
*/
template <class S, class P>
class PmergeMe
{
    private:
        S   seq;
        P   pairs;
        S   sorted;

        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);

        S setSeq(char *argv[]);

        //helping functions for sorting algorithm
        void creatingPairs();

    protected:
        S &getSeq() const;
        S &getSorted() const;
        P &getPairs() const;

    public:
        double time;

        PmergeMe();
        PmergeMe(char *argv[]);
        virtual ~PmergeMe();

        void printSeq(bool b);

        void sorting();

        class InvalidInput : public std::exception
	    {
		    const  char* what() const noexcept
		    {
		    	return "Invalid input";
		    }
	    };
};

#include "PmergeMe.tpp"
#include "PmergeMeSort.tpp"