/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:04:31 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:56:12 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Safa("Safa");
	ClapTrap Oliver("Oliver");

	std::cout << std::endl;

	Safa.attack("Oliver");
	Oliver.takeDamage(5);

	std::cout << std::endl;

	Safa.attack("Oliver");
	Oliver.takeDamage(1);

	std::cout << std::endl;

	Safa.attack("Oliver");
	Oliver.takeDamage(1);

	std::cout << std::endl;

	Oliver.beRepaired(7);

	std::cout << std::endl;

	Safa.attack("Oliver");
	Oliver.takeDamage(10);

	std::cout << std::endl;

	return EXIT_SUCCESS;
}
