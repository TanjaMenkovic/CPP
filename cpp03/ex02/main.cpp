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

#include "FragTrap.hpp"

using std::cout;
using std::endl;

int main(void)
{
	FragTrap Maslina("Maslina");
	FragTrap Safa("Safa");

	cout << endl;

	Maslina.attack("Safa");
	Safa.takeDamage(25);

	cout << endl;

	Maslina.attack("Safa");
	Safa.takeDamage(32);

	cout << endl;

	Maslina.attack("Safa");
	Safa.takeDamage(20);

	cout << endl;

	Safa.beRepaired(77);

	cout << endl;

	Maslina.attack("Safa");
	Safa.takeDamage(10);

	cout << endl;

	Safa.highFivesGuys();

	cout << endl;

	return EXIT_SUCCESS;
}
