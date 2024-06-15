/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:09:24 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/15 12:09:26 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	public:
		DiamondTrap(string name);
		DiamondTrap(const DiamondTrap &to_copy);
		DiamondTrap& operator=(const DiamondTrap &original);
		~DiamondTrap(void);

        using	ScavTrap::attack;
		void whoAmI(void);

	protected:
		string			_name;
        DiamondTrap(void);
};

#endif
