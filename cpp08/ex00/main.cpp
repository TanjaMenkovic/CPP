#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    try {
        // Using easyfind to find an element in the vector
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl; // Output: Found: 3

        // Attempting to find a non-existing element, will throw exception
        it = easyfind(vec, 10);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl; // Output: Target integer not found in container
    }

    return 0;
}
