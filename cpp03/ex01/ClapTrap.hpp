#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

using std::string;
using std::cout;
using std::endl;

class ClapTrap {
	public:
		ClapTrap(string name);
		ClapTrap(const ClapTrap &to_copy);
		ClapTrap& operator=(const ClapTrap &original);
		~ClapTrap(void);

		void attack(const string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif
