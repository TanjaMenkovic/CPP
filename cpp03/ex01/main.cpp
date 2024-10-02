/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:05:32 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:59:15 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Maslina("Maslina");
	ScavTrap Safa("Safa");

	std::cout << std::endl;

	Maslina.attack("Safa");
	Safa.takeDamage(5);

	std::cout << std::endl;

	Maslina.attack("Safa");
	Safa.takeDamage(1);

	std::cout << std::endl;

	Maslina.attack("Safa");
	Safa.takeDamage(1);

	std::cout << std::endl;

	Safa.beRepaired(7);

	std::cout << std::endl;

	Maslina.attack("Safa");
	Safa.takeDamage(10);

	std::cout << std::endl;

	Maslina.guardGate();
	Safa.guardGate();

	std::cout << std::endl;

	return EXIT_SUCCESS;
}
