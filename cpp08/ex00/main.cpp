#include <vector>
#include "easyfind.hpp"

static void searchforvalue(std::vector<int> vec, int value)
{
    try 
    {
        std::vector<int>::iterator it;

        std::cout << "\nSearaching for value " << value << std::endl;
        it = easyfind(vec, value);
        std::cout << "Found: " << *it << std::endl;

        std::cout << std::endl;
    }
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 643, 111, 9};
    std::string valueStr;
    int         value;

    std::cout << "What value would you like to find: " << std::endl;
    getline(std::cin, valueStr);
        
    if (std::cin.eof() == true)
	{
	    std::cin.clear();
	    std::cout << std::endl;
	}
    try 
    {
        value = std::stoi(valueStr);
    }
    catch (std::invalid_argument const& e) 
    {
        std::cerr << "Error: Invalid input. Please enter an integer value." << std::endl;
        return 1;
    }
    catch (std::out_of_range const& e) 
    {
        std::cerr << "Error: Value out of range." << std::endl;
        return 1;
    }
    
    searchforvalue(vec, value);

    return 0;
}
