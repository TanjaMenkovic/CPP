#pragma once

#include "PmergeMe.hpp"

class PmergeMeVec : public PmergeMe <std::vector<int>, std::vector<std::pair<int, int>>>
{
    private:
        PmergeMeVec(PmergeMeVec const &other);  
        PmergeMeVec &operator=(PmergeMeVec const &other);

    public:
        PmergeMeVec(char *argv[]);
        ~PmergeMeVec();
        
        void printTime() const;
};