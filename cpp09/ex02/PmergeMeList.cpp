#include "PmergeMeList.hpp"
#include <list>

PmergeMeList::PmergeMeList(char* argv[])
    : PmergeMe<std::list<int>, std::list<std::pair<int, int>>>(argv) {}

PmergeMeList::~PmergeMeList(){}

// PmergeMeList::PmergeMeList(PmergeMeList const &other) 
// {
//   (void)other;
// }

PmergeMeList &PmergeMeList::operator=(PmergeMeList const &other) 
{
  (void)other;
  return *this;
}

void PmergeMeList::printTime() const
{
    std::cout << "Sorting time (list): " << time << " ms" << std::endl;
}

