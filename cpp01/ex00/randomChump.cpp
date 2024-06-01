#include "Zombie.hpp"

void	randomChump(std::string name)
{
	if (name.empty())
	{
		std::cout << "Please provide a name to the zombie..." << std::endl;
		return;
	}

	Zombie zombi(name);
	zombi.announce();
}
