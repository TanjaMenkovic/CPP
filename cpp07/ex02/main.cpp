#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

// //1st version of main:
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

// //2nd version of main:
// int main() 
// {
// 	// Create an Array of integers with 5 elements
//     Array<int> arr(5);

//     // Initialize the array with values
//     for (unsigned int i = 0; i < arr.size(); ++i) {
//         arr[i] = (i + 1) * 10; // Assign values: 10, 20, 30, 40, 50
//     }

//     // Print the values of the array
//     std::cout << "Original array values: ";
//     for (unsigned int i = 0; i < arr.size(); ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;

//     // Attempt to access an out-of-bounds index
//     try 
//     {
//         std::cout << arr[10] << std::endl; // This should throw a bounds exception
//     }
//     catch (std::exception& e) 
//     {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//     }

//     // Print size
//     std::cout << "Size of original array: " << arr.size() << std::endl;
    
//     return 0;
// }

//3rd version of main:
int main(int, char**)
{
    // Initialize arrays
    std::cout << "Initializing array of size " << MAX_VAL << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    std::cout << "Filling the array with random values and copying to mirror array." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // Test copy constructor and assignment operator
    std::cout << "\nTesting copy constructor and assignment operator.\n" << std::endl;
    {
        std::cout << "Creating a copy of 'numbers' using assignment operator." << std::endl;
        Array<int> tmp = numbers; // Testing assignment operator

        std::cout << "Creating a copy of 'tmp' using copy constructor." << std::endl;
        Array<int> test(tmp); // Testing copy constructor

        // Validate if the copy constructor and assignment operator worked correctly
        bool copy_valid = true;
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (tmp[i] != numbers[i] || test[i] != numbers[i])
            {
                copy_valid = false;
                std::cerr << "Copy validation failed at index " << i << std::endl;
                break;
            }
        }

        if (copy_valid)
            std::cout << "Copy constructor and assignment operator work correctly!" << std::endl;
    }

    // Validate that the original array hasn't changed
    std::cout << "\nValidating that 'numbers' array has the correct values after copy tests." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "Validation failed: 'numbers' and 'mirror' differ at index " << i << std::endl;
            return 1;
        }
    }
    std::cout << "Original 'numbers' array matches the 'mirror' array!" << std::endl;

    // Test out-of-bounds access
    std::cout << "\nTesting out-of-bounds access.\n" << std::endl;
    try
    {
        std::cout << "Attempting to access index -2 (should throw an exception)." << std::endl;
        numbers[-2] = 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Attempting to access index " << MAX_VAL << " (should throw an exception)." << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // Refill the array with random values
    std::cout << "\nRefilling the array with new random values." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    // Testing empty array
    std::cout << "\nTesting behavior with an empty array.\n" << std::endl;
    Array<int> emptyArray;
    std::cout << "Created an empty array." << std::endl;
    try
    {
        std::cout << "Attempting to access index 0 in the empty array (should throw an exception)." << std::endl;
        emptyArray[0] = 42;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // Clean up
    std::cout << "\nCleaning up memory.\n" << std::endl;
    delete[] mirror;
    std::cout << "Deleted 'mirror' array. Program completed successfully!" << std::endl;

    return 0;
}
