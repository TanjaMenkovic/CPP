#include "Array.hpp"

int main() 
{
	Array<int> arr(40);
	Array<int> empty;

	arr[0] = 42;
	arr[1] = 42;

	try{
		arr[80] = 69;
	}
	catch(std::exception& e){
		std::cout << "too high bounds exception caught" << std::endl;
	}

	try{
		empty[-1] = 69;
	}
	catch(std::exception& e){
		std::cout << "too low bounds exception caught" << std::endl;
	}
    
	std::cout << "size of empty: " << empty.size() << std::endl;
	std::cout << "size of arr: " << arr.size() << std::endl;
}
