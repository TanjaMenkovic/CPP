/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:08:05 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:17:14 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap Maslina("Maslina");
	FragTrap Safa("Safa");

	std::cout << std::endl;

	Maslina.attack("Safa");
	Safa.takeDamage(25);

	std::cout << std::endl;

	Maslina.attack("Safa");
	Safa.takeDamage(32);

	std::cout << std::endl;

	Maslina.attack("Safa");
	Safa.takeDamage(20);

	std::cout << std::endl;

	Safa.beRepaired(77);

	std::cout << std::endl;

	Maslina.attack("Safa");
	Safa.takeDamage(10);

	std::cout << std::endl;

	Safa.highFivesGuys();

	std::cout << std::endl;

	return 0;
}
