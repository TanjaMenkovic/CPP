#include "Array.hpp"

int main() 
{
	// Create an Array of integers with 5 elements
    Array<int> arr(5);

    // Initialize the array with values
    for (unsigned int i = 0; i < arr.size(); ++i) {
        arr[i] = (i + 1) * 10; // Assign values: 10, 20, 30, 40, 50
    }

    // Print the values of the array
    std::cout << "Original array values: ";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Attempt to access an out-of-bounds index
    try 
    {
        std::cout << arr[10] << std::endl; // This should throw a bounds exception
    }
    catch (std::exception& e) 
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Print size
    std::cout << "Size of original array: " << arr.size() << std::endl;
    
    return 0;
}
