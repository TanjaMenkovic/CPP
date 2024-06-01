#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <iomanip>
# include <string>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();

		void setName(std::string name);
		const std::string& getName(void) const;

		void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
