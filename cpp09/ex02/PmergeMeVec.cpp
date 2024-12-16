#include "PmergeMeVec.hpp"
#include <vector>

PmergeMeVec::PmergeMeVec(char* argv[])
    : PmergeMe<std::vector<int>, std::vector<std::pair<int, int>>>(argv) {}

PmergeMeVec::~PmergeMeVec() {}

// PmergeMeVec::PmergeMeVec(const PmergeMeVec& other)
// {
//   (void)other;
// }

PmergeMeVec &PmergeMeVec::operator=(PmergeMeVec const &other) 
{
  (void)other;
  return *this;
}

void PmergeMeVec::printTime() const 
{
    std::cout << "Sorting time (vector): " << time << " ms" << std::endl;
}
