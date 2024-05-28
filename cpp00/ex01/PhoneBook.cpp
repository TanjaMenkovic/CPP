/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:20:09 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/05/28 13:20:11 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
default constructor
*/
PhoneBook::~PhoneBook()
{
	std::cout << "There is no contact in this phone book!" << std::endl;
}

/*
constructor
*/
PhoneBook::PhoneBook()
{
	int	i = 0;

	while (i < 8)
	{
		this->_contacts[i].set_index(-1);
		i++;
	}
}
