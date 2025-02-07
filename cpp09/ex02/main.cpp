#include "PmergeMe.hpp"
#include "PmergeMeVec.hpp"
#include "PmergeMeList.hpp"

/*
Run code with any type of sequence of numbers like:
./PmergeMe 634 32 131 5 3 1 44 2 42 5  2 2 2 2 2 2 2 2 

OR
shuf -i 1-1000 -n 3000 | tr "\n" " " | xargs ./PmergeMe
*/

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "Error: not enough arguments." << std::endl;
    return 1; 
  }
  argv++;
  
  try
  {
    PmergeMe< std::vector<int>, std::vector<std::pair<int, int> > > *vector = new PmergeMeVec(argv);
    vector->sorting();

    PmergeMe < std::list<int>, std::list<std::pair<int, int> > > *list = new PmergeMeList(argv);
    list->sorting();
    
    vector->printSeq(true);
    vector->printSeq(false);
    vector->printTime();
    list->printTime();

    delete vector;
    delete list;
  } 
  catch (std::exception &e) 
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}