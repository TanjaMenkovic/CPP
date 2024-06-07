/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:05:32 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:05:35 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	ScavTrap Maslina("Maslina");
	ScavTrap Safa("Safa");

	cout << endl;

	Maslina.attack("Safa");
	Safa.takeDamage(5);

	cout << endl;

	Maslina.attack("Safa");
	Safa.takeDamage(1);

	cout << endl;

	Maslina.attack("Safa");
	Safa.takeDamage(1);

	cout << endl;

	Safa.beRepaired(7);

	cout << endl;

	Maslina.attack("Safa");
	Safa.takeDamage(10);

	cout << endl;

	Maslina.guardGate();
	Safa.guardGate();

	cout << endl;

	return EXIT_SUCCESS;
}
