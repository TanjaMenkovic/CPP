#include "PmergeMe.hpp"
#include "PmergeMeVec.hpp"
#include "PmergeMeList.hpp"

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1; 
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
    std::cerr << "\tException caught:" << " " << e.what() << std::endl;
  }
  return 0;
}