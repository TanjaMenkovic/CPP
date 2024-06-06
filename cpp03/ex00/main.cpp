#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Safa("Safa");
	ClapTrap Oliver("Oliver");

	cout << endl;

	Safa.attack("Oliver");
	Oliver.takeDamage(5);

	cout << endl;

	Safa.attack("Oliver");
	Oliver.takeDamage(1);

	cout << endl;

	Safa.attack("Oliver");
	Oliver.takeDamage(1);

	cout << endl;

	Oliver.beRepaired(7);

	cout << endl;

	Safa.attack("Oliver");
	Oliver.takeDamage(10);

	cout << endl;

	return EXIT_SUCCESS;
}
