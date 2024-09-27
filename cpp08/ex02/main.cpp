#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    
    std::cout << "Creating slack of numbers 5, 6, 7, 8............\n";
    mstack.push(5);
    mstack.push(6);
    mstack.push(7);
    mstack.push(8);

    std::cout << std::endl;

    std::cout << "Print the top element of slack: ";
    std::cout << mstack.top() << std::endl;

    std::cout << std::endl;

    std::cout << "Removing the top element of slack..............\n";
    mstack.pop();

    std::cout << "Print the top element of slack: ";
    std::cout << mstack.top() << std::endl;

    std::cout << std::endl;

    std::cout << "Size of slack: ";
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

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl;

    std::cout << "Iterating through stack from end to beginning:\n";
    it = mstack.begin();

    --ite;
    --it;
    while (it != ite)
    {
        std::cout << *ite << std::endl;
        --ite;
    }

    std::cout << std::endl;

    std::cout << "creating a copy................\n";
    std::stack<int> s(mstack);
    
    std::cout <<"Top element of original slack is: " << mstack.top() << ", and of copy slack is: " << s.top() << std::endl;

    return 0;
}