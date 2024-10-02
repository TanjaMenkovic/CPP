/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:40:45 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 10:59:08 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
constructor
*/
Zombie::Zombie(std::string name) : _name(name) {}

/*
destructor
*/
Zombie::~Zombie()
{
	std::cout << "Zombi " << this->_name << " died!!!" << std::endl;
}

/*
setter
*/
void Zombie::setName(std::string name) {
    this->_name = name;
}

/*
getter
*/
const std::string& Zombie::getName(void) const {
    return this->_name;
}

/*
functions (methods)
*/
void Zombie::announce(void)
{
	if (this->_name.empty())
		return ;
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
