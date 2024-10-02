/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:09:24 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:21:30 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &to_copy);
		DiamondTrap& operator=(const DiamondTrap &original);
		~DiamondTrap(void);

        void attack(const std::string &target);
		void whoAmI(void);

	protected:
		std::string			_name;
        DiamondTrap(void);
};

#endif
