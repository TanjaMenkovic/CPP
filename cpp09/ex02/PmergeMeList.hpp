#pragma once

#include "PmergeMe.hpp"

class PmergeMeList  : public PmergeMe <std::list<int>, std::list<std::pair<int, int>>>
{
    private:
        PmergeMeList( PmergeMeList const &other );  
        PmergeMeList &operator=( PmergeMeList const &other);

    public:
        PmergeMeList(char *argv[]);
        ~PmergeMeList();

        void printTime() const;
};