/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:05:14 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:05:24 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
class ScavTrap : public ClapTrap {

	public:
		ScavTrap(string _name);
		~ScavTrap(void);

		void attack(const string& target);
		void guardGate(void);

	private:
		ScavTrap(void);
};

#endif
