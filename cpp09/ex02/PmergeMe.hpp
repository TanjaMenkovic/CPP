#pragma once

#include <iostream>
#include <exception>
#include <cctype>
#include <cstdlib>  // For std::strtol (long int)

#include <algorithm>
#include <vector>
#include <list>


/*
template class will have everything universal
for any type of container and then subclasses
will be separately vectors and lists

class S - sequence
class P - pairs
*/
template <class S, class P>
class PmergeMe
{
    private:
        const S seq;
        U       pairs;


        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);
    protected:

    public:
        PmergeMe();
        PmergeMe(char *argv[]);
        virtual ~PmergeMe();
};

class PmergeMeVec : public PmergeMe <std::vector<int>, std::vector<std::pair<int, int>>>
{};

class PmergeMeList  : public PmergeMe <std::list<int>, std::list<std::pair<int, int>>>
{};