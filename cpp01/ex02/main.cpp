#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(void)
{
	string brain = "HI THIS IS BRAIN";
	string *stringPTR = &brain;
	string &stringREF = brain;

	cout << "Memory address of the string variable:\t" << &brain << endl;
	cout << "Memory address held by stringPTR:\t" << stringPTR << endl;
	cout << "Memory address held by stringREF:\t" << &stringREF << endl;

	cout << "\nValue of the string variable:\t" << brain << endl;
	cout << "Value pointed to by stringPTR:\t" << *stringPTR << endl;
	cout << "Value pointed to by stringREF:\t" << stringREF << endl;

	return 0;
}
