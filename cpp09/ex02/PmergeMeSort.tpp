/*

*/

/*
1st step: creating sorted pairs in ascending order
*/
template <class S, class P>
void PmergeMe<S, P>::creatingPairs()
{
    typename    S::iterator it = getSeq().begin();
    int         first = *it;
    int         second;

    for (; it != getSeq().end(); ++it)
    {
        // Check if there's another element to form a pair
        if (it != getSeq().end())
        {
            second = *it;
            ++it;
            // Swap if necessary to make sure first >= second
            if (first < second)
                std::swap(first, second);

            // Store the sorted pair
            getPairs().push_back(std::make_pair(first, second));
        }
    }
    first = *it;
}

/*
2nd step: 
*/


/*
Jacobsthal Sequence Generator -This function calculates Jacobsthal numbers, 
which are recursively defined and provide optimized positions for insertion 
to minimize the total number of comparisons.
*/
template <class S, class P>
int PmergeMe<S, P>::jacobsthal(int n)
{
  if (n == 0) return 0;
  if (n == 1) return 1;
  return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}


/*
Sorting algorithm
*/
template <class S, class P>
void PmergeMe<S, P>::sorting()
{
    clsck_t start = clock();

    if (getSeq().size() == 1)
        this->sorted = this->seq;
    else
    {
        creatingPairs();
    }
    time = (double)(clock() - start) / (clock_t)1000000 * 1000;
}