/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:08:05 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:08:15 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	DiamondTrap	diamondTrap("Sahra");

	diamondTrap.whoAmI();
	diamondTrap.attack("random human");
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.takeDamage(20);
	diamondTrap.beRepaired(10);
	diamondTrap.takeDamage(100);

	return 0;
}
