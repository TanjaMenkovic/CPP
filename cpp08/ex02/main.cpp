#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    
    std::cout << "Creating stack of numbers 5, 6, 7, 8............\n";
    mstack.push(5);
    mstack.push(6);
    mstack.push(7);
    mstack.push(8);

    std::cout << std::endl;

    std::cout << "Print the top element of stack: ";
    std::cout << mstack.top() << std::endl;

    std::cout << std::endl;

    std::cout << "Removing the top element of stack..............\n";
    mstack.pop();

    std::cout << "Print the top element of stack: ";
    std::cout << mstack.top() << std::endl;

    std::cout << std::endl;

    std::cout << "Size of stack: ";
    std::cout << mstack.size() << std::endl;

    std::cout << std::endl;

    std::cout << "Adding elements 3, 5, 737, 0..............\n";
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << std::endl;

    std::cout << "Iterating through stack from beginning to the end:\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl;

    std::cout << "Iterating through stack from end to beginning:\n";
    if (mstack.size() > 0) {
        ite--; // Set to the last element
        while (ite != mstack.begin()) {
            std::cout << *ite << std::endl;
            --ite;
        }
        std::cout << *ite << std::endl; // Print the first element
    }

    std::cout << std::endl;

    std::cout << "Creating a copy................\n";
    std::stack<int> s(mstack);
    
    std::cout <<"Top element of original stack is: " << mstack.top() << ", and of copy stack is: " << s.top() << std::endl;

    return 0;
}

// #include <iostream>
// #include <list>
// #include "MutantStack.hpp"

// // Template function for std::list (or any container with push_back, pop_back, back)
// template <typename TContainer>
// void testContainer()
// {
//     TContainer container;
    
//     std::cout << "Creating stack of numbers 5, 6, 7, 8............\n";
//     container.push_back(5); // For std::list
//     container.push_back(6);
//     container.push_back(7);
//     container.push_back(8);

//     std::cout << std::endl;

//     std::cout << "Print the top element of container: ";
//     std::cout << container.back() << std::endl; // For std::list

//     std::cout << std::endl;

//     std::cout << "Removing the top element of container..............\n";
//     container.pop_back(); // For std::list

//     std::cout << "Print the top element of container: ";
//     std::cout << container.back() << std::endl; // For std::list

//     std::cout << std::endl;

//     std::cout << "Size of container: ";
//     std::cout << container.size() << std::endl;

//     std::cout << std::endl;

//     std::cout << "Adding elements 3, 5, 737, 0..............\n";
//     container.push_back(3);
//     container.push_back(5);
//     container.push_back(737);
//     container.push_back(0);

//     std::cout << std::endl;

//     std::cout << "Iterating through container from beginning to the end:\n";
//     typename TContainer::iterator it = container.begin();
//     typename TContainer::iterator ite = container.end();

//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     std::cout << std::endl;

//     std::cout << "Iterating through container from end to beginning:\n";
//     if (container.size() > 0) {
//         --ite; // Set to the last element
//         while (ite != container.begin()) {
//             std::cout << *ite << std::endl;
//             --ite;
//         }
//         std::cout << *ite << std::endl; // Print the first element
//     }

//     std::cout << std::endl;
// }

// // Template specialization for MutantStack
// template <>
// void testContainer<MutantStack<int>>()
// {
//     MutantStack<int> mstack;
    
//     std::cout << "Creating stack of numbers 5, 6, 7, 8............\n";
//     mstack.push(5); // Using push for MutantStack
//     mstack.push(6);
//     mstack.push(7);
//     mstack.push(8);

//     std::cout << std::endl;

//     std::cout << "Print the top element of stack: ";
//     std::cout << mstack.top() << std::endl; // Using top for MutantStack

//     std::cout << std::endl;

//     std::cout << "Removing the top element of stack..............\n";
//     mstack.pop(); // Using pop for MutantStack

//     std::cout << "Print the top element of stack: ";
//     std::cout << mstack.top() << std::endl; // Using top for MutantStack

//     std::cout << std::endl;

//     std::cout << "Size of stack: ";
//     std::cout << mstack.size() << std::endl;

//     std::cout << std::endl;

//     std::cout << "Adding elements 3, 5, 737, 0..............\n";
//     mstack.push(3); // Using push for MutantStack
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);

//     std::cout << std::endl;

//     std::cout << "Iterating through stack from beginning to the end:\n";
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     std::cout << std::endl;

//     std::cout << "Iterating through stack from end to beginning:\n";
//     if (mstack.size() > 0) {
//         --ite; // Set to the last element
//         while (ite != mstack.begin()) {
//             std::cout << *ite << std::endl;
//             --ite;
//         }
//         std::cout << *ite << std::endl; // Print the first element
//     }

//     std::cout << std::endl;
// }

// int main()
// {
//     // Test with MutantStack
//     std::cout << "Testing with MutantStack<int>\n";
//     testContainer<MutantStack<int>>();

//     // Test with std::list
//     std::cout << "Testing with std::list<int>\n";
//     testContainer<std::list<int>>();

//     return 0;
// }

