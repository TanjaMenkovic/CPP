/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:42:52 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 08:42:53 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zombies;

	if (N < 1)
	{
		std::cout << "Can't create less than 1 zombie." << std::endl;
		return NULL;
	}

	int i = 0;
	zombies = new Zombie[N];
	while (i < N)
	{
		zombies[i].setName(name);
		i++;
	}

	return zombies;
}
