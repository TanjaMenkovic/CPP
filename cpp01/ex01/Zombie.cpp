#include "Zombie.hpp"

/*
constructor
*/
Zombie::Zombie()
{
}

/*
destructor
*/
Zombie::~Zombie()
{
	std::cout << "Zombi " << this->_name << " died!!!" << std::endl;
}

/*
setter
*/
void Zombie::setName(std::string name) {
    this->_name = name;
}

/*
getter
*/
const std::string& Zombie::getName(void) const {
    return this->_name;
}

/*
functions (methods)
*/
void Zombie::announce(void)
{
	if (this->_name.empty())
		return ;
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
