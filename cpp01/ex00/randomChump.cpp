/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:41:24 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 08:41:26 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	if (name.empty())
	{
		std::cout << "Please provide a name to the zombie..." << std::endl;
		return;
	}

	Zombie zombi(name);
	zombi.announce();
}
