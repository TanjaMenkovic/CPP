// setters
template <class S, class P>
S PmergeMe<S, P>::setSeq(char *argv[])
{
    int number;
    char *endptr;
    S seq;

    for (int i = 0; argv[i] != NULL; i++)
    {
        if (argv[i][0] == '\0')
            throw InvalidInput();
        number = std::strol(argv[i], &endptr, 10);
        if (*endptr != '\0' || number < 0)
            throw InvalidInput();
                
        seq.push_back(number);
    }
    return seq;    
}

// constructors & destructor
template <class S, class P>
PmergeMe<S, P>::PmergeMe() {}

template <class S, class P>        
PmergeMe<S, P>::PmergeMe(char *argv[]) : seq(setSeq(argv)) {}

template <class S, class P>      
PmergeMe<S, P>::~PmergeMe() {}

template <class S, class P>
PmergeMe<S, P>::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

template <class S, class P>
PmergeMe<S, P> &PmergeMe<S, P>::operator=(const PmergeMe<S, P> &src)
{
    if (this != src)
    {
        this->number = src.number;
        this->seq = src.seq;
    }
    return *this;
}

// getters
template <class S, class P>
S &PmergeMe<S, P>::getSeq() const
{
    return seq;
}

template <class S, class P>
S &PmergeMe<S, P>::getSorted() const
{
    return sorted;
}

template <class S, class P>
P &PmergeMe<S, P>::getPairs() const
{
    return pairs;
}

// printing functions
template <class S, class P>
void PmergeMe<S, P>::printSeq(bool b)
{
    S   temp;
    int i = 0;
    typename S::const_iterator it;

    if (b)
    {
        std::cout << "Before: ";
        temp = getSeq();
    }
    else
    {
        std::cout << "After: ";
        temp = getSorted();
    }
    
    for (it = temp.begin(); it != temp.end() && i < 10; it++)
    {
        std::cout << *it << " ";
        i++;
        if (i == 10)
            std::cout << "...only first 10 elements are shown...";
    }
    std::cout << std::endl;
}