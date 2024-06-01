#include "Zombie.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int	main(void)
{
	string	input;
	Zombie	*new_zombie;

	cout << "\n\nCreating a zombie on the heap:\n" << endl;
	cout << "Name the heap Zombie: ";
	getline(cin, input);
	if (cin.eof() == true)
	{
		cin.clear();
		clearerr(stdin);
		cout << endl;
	}
	new_zombie = newZombie(input);
	new_zombie->announce();
	delete new_zombie;

	cout << "\n----------------------------------\n" << endl;

	cout << "Creating a zombie on the stac:\n" << endl;
	getline(cin, input);
	if (cin.eof() == true)
	{
		cin.clear();
		clearerr(stdin);
		cout << endl;
	}
	randomChump(input);

	return 0;
}
