#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
class ScavTrap: virtual public ClapTrap {

	public:
		ScavTrap(void);
		ScavTrap(string _name);
		ScavTrap(const ScavTrap &to_copy);
		ScavTrap& operator=(const ScavTrap &original);
		~ScavTrap(void);

		void attack(const string& target);
		void guardGate(void);
};

#endif
