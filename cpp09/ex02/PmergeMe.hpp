#pragma once

#include <iostream>
#include <exception>
#include <cctype>
#include <cstdlib>  // For std::strtol
#include <algorithm>
#include <vector>
#include <list>
#include <utility>  // For std::pair
#include <iterator> // For std::next
#include <ctime>    // For clock()


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
    const S seq;          // Input sequence
    P pairs;        // Pairs of elements
    S sorted;       // Sorted elements
    S unsolved;     // Elements to solve
    S position;     // Insert positions

    PmergeMe(const PmergeMe &src)
    {
        *this = src;
    }

    PmergeMe &operator=(const PmergeMe &src)
    {
        if (this != src)
        {
            this->number = src.number;
            this->seq = src.seq;
        }
        return *this;
    }

    // Parse sequence from input arguments
    S setSeq(char *argv[])
    {
        S seq;
        for (int i = 0; argv[i] != NULL; i++)
        {
            if (argv[i][0] == '\0')
                throw InvalidInput();
            char *endptr;
            int number = std::strtol(argv[i], &endptr, 10);
            if (*endptr != '\0' || number < 0)
                throw InvalidInput();
            seq.push_back(number);
        }
        return seq;
    }

    // Create sorted pairs in descending order (first >= second)
    // void creatingPairs()
    // {
    //     // typename S::const_iterator it = getSeq().begin();

    //     // int         first = *it;
    //     // int         second;

    //     // for (; it != getSeq().end(); ++it)
    //     // {
    //     //     // Check if there's another element to form a pair
    //     //     if (it != getSeq().end())
    //     //     {
    //     //         second = *it;
    //     //         ++it;
    //     //         // Swap if necessary to make sure first >= second
    //     //         if (first < second)
    //     //             std::swap(first, second);

    //     //         // Store the sorted pair
    //     //         getPairs().push_back(std::make_pair(first, second));
    //     //     }
    //     //     first = *it;
    //     // }
    //     typename S::const_iterator it = getSeq().begin();
    //     while (it != getSeq().end())
    //     {
    //         int first = *it++;
    //         if (it != getSeq().end())
    //         {
    //             int second = *it++;
    //             if (first < second)
    //                 std::swap(first, second);
    //             getPairs().push_back(std::make_pair(first, second));
    //         }
    //     }
    // }
    void creatingPairs()
{
    typename S::const_iterator it = getSeq().begin();
    while (it != getSeq().end())
    {
        int first = *it++;
        if (it != getSeq().end())
        {
            int second = *it++;
            if (first < second)
                std::swap(first, second);
            getPairs().push_back(std::make_pair(first, second));
        }
    }

    // Debug: Print pairs
    std::cout << "Pairs created: ";
    for (auto &pair : pairs)
    {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;
}


    // Merge sort the pairs by the first value in descending order
    // void merge(typename P::iterator begin, typename P::iterator end)
    // {
    //     if (std::distance(begin, end) > 1)
    //     {
    //         typename P::iterator mid = begin;
    //         std::advance(mid, std::distance(begin, end) / 2);

    //         merge(begin, mid);
    //         merge(mid, end);

    //         P first_half(begin, mid);
    //         P second_half(mid, end);

    //         typename P::iterator it1 = first_half.begin();
    //         typename P::iterator it2 = second_half.begin();
    //         typename P::iterator it = begin;

    //         while (it1 != first_half.end() && it2 != second_half.end())
    //         {
    //             if (it1->first >= it2->first)
    //                 *it++ = *it1++;
    //             else
    //                 *it++ = *it2++;
    //         }

    //         while (it1 != first_half.end())
    //             *it++ = *it1++;
    //         while (it2 != second_half.end())
    //             *it++ = *it2++;
    //     }
    // }
    void merge(typename P::iterator begin, typename P::iterator mid, typename P::iterator end)
{
    P first_half(begin, mid);
    P second_half(mid, end);

    typename P::iterator it1 = first_half.begin();
    typename P::iterator it2 = second_half.begin();
    typename P::iterator it = begin;

    while (it1 != first_half.end() && it2 != second_half.end())
    {
        if (it1->first <= it2->first)
            *it++ = *it1++;
        else
            *it++ = *it2++;
    }
    while (it1 != first_half.end())
        *it++ = *it1++;
    while (it2 != second_half.end())
        *it++ = *it2++;
}

void mergeSort(typename P::iterator begin, typename P::iterator end)
{
    if (std::distance(begin, end) > 1)
    {
        typename P::iterator mid = begin;
        std::advance(mid, std::distance(begin, end) / 2);
        mergeSort(begin, mid);
        mergeSort(mid, end);
        merge(begin, mid, end);
    }
}


    /*
    Jacobsthal Sequence Generator - This function calculates Jacobsthal numbers, 
    which are recursively defined and provide optimized positions for insertion 
    to minimize the total number of comparisons.
    */ 
    int jacobsthal(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
    }

    S insertSequence(size_t n)
    {
        S jacobSequence;
        S insertSeq;
        size_t index = 3;

        // Generate Jacobsthal sequence
        size_t value = jacobsthal(index);
        while (value < n - 1)
        {
            jacobSequence.push_back(value);
            value = jacobsthal(++index);
        }

        // Generate positions from Jacobsthal
        size_t prevJacobVal = 1;
        for (auto jacobVal : jacobSequence)
        {
            for (size_t i = jacobVal; i > prevJacobVal; --i)
                insertSeq.push_back(i);
            prevJacobVal = jacobVal;
        }
        for (size_t i = prevJacobVal + 1; i <= n; ++i)
            insertSeq.push_back(i);

        return insertSeq;
    }

    typename S::iterator binarySearch(int value, typename S::iterator left, typename S::iterator right)
{
    while (std::distance(left, right) > 0)
    {
        typename S::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        if (value >= *mid) // Change to >= to handle duplicates correctly
            left = std::next(mid); // Move left forward
        else
            right = mid; // Move right backward
    }
    return left;
}

void insertionSort()
{
    position = insertSequence(unsolved.size()); // Generate Jacobsthal-based positions
    
    // Define iterator to track the unsolved elements
    typename S::iterator unsolvedIt = unsolved.begin();

    for (typename S::iterator pos = position.begin(); pos != position.end(); pos++)
    {
        // Get the value to insert from `unsolved`
        typename S::iterator toInsert = unsolvedIt;
        std::cout << "ELEMENT " << *toInsert << ", POSITION " << *pos << std::endl;

        unsolvedIt++; // Move to the next unsolved element for the next iteration

        // Perform binary search to find the correct insertion point in `sorted`
        typename S::iterator realIndex = binarySearch(*toInsert, sorted.begin(), sorted.end());

        // Debug: Print the element being inserted and its position
        std::cout << "Inserting " << *toInsert << " at position " << std::distance(sorted.begin(), realIndex) << std::endl;

        sorted.insert(realIndex, *toInsert); // Insert the element into `sorted`
    }

    // Handle the last element if the input sequence size is odd and it wasn't inserted
    if (unsolvedIt != unsolved.end()) // Ensure we still have the last unpaired element
    {
        int val = *unsolvedIt; // Last unpaired element
        typename S::iterator realIndex = binarySearch(val, sorted.begin(), sorted.end());

        // Debug: Print insertion of the last element
        std::cout << "Inserting last element " << val << " at position " << std::distance(sorted.begin(), realIndex) << std::endl;

        sorted.insert(realIndex, val);  // Insert the last element
    }
}


protected:
    const S &getSeq() const
    {
        return seq;
    }

    S &getSorted()
    {
        return sorted;
    }

    P &getPairs()
    {
        return pairs;
    }

    S &getUnsolved() 
    {
        return unsolved;
    }

    S &getPosition() 
    {
        return position;
    }

public:
    double time;

    PmergeMe() {}

    PmergeMe(char *argv[]) : seq(setSeq(argv)) {}

    virtual ~PmergeMe() {}

    /*
     function for printing sequence before and after sorting it
    if b == true, it will print sequience before sorting
    if b == false, it will print after sorting
    */
    void printSeq(bool before)
    {
        S   temp;
        int i = 0;
        typename S::iterator it;

        if (before)
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

    // Perform sorting
    void sorting()
{
    clock_t start = clock();

    if (seq.size() == 1)
    {
        sorted = seq; // Single element, already sorted
    }
    else
    {
        // Step 1: Create pairs
        creatingPairs();

        // Step 2: Sort pairs by the first element
        mergeSort(pairs.begin(), pairs.end());

        // Step 3: Split pairs into `sorted` (first elements) and `unsolved` (second elements)
        for (auto pair : pairs)
        {
            sorted.push_back(pair.first);   // Push the larger element into `sorted`
            unsolved.push_back(pair.second); // Push the smaller element into `unsolved`
        }

        // Debug: Print sorted and unsolved
std::cout << "Sorted (after splitting pairs): ";
for (auto &val : sorted)
    std::cout << val << " ";
std::cout << std::endl;

std::cout << "Unsolved (after splitting pairs): ";
for (auto &val : unsolved)
    std::cout << val << " ";
std::cout << std::endl;

        // Step 4: Insert unsolved elements into `sorted` using Jacobsthal and binary search
        insertionSort();

        // Step 5: Handle the last element if the input sequence size is odd
        if (seq.size() % 2 != 0)
        {
            int lastVal = seq.back(); // Last unpaired element
            auto realIndex = binarySearch(lastVal, sorted.begin(), sorted.end());
            sorted.insert(realIndex, lastVal);
        }
    }

    // Measure and store time taken for sorting
    time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000.0;
}



    virtual void printTime() const = 0;

    class InvalidInput : public std::exception
    {
        const char *what() const noexcept 
        { 
            return "Invalid input"; 
            }
    };
};
