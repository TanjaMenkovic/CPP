#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <iomanip>
# include <string>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(std::string name);
		~Zombie();

		void setName(std::string name);
		const std::string& getName(void) const;

		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
