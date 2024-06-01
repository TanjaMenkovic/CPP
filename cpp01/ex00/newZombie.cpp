#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	if (name.empty())
	{
		std::cout << "Please provide a name to the zombie..." << std::endl;
		return NULL;
	}

	return new Zombie(name);
}
