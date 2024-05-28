/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:20:21 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/05/28 13:20:23 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
default constructor
*/
Contact::~Contact()
{
	std::cout << "There is no contact!" << std::endl;
}

/*
constructor
*/
Contact::Contact()
{
	this->_index = -1;
}

/*
setters
*/
void	Contact::set_index(int index)
{
	this->_index = index;
}

/*
getters
*/
int	Contact::get_index(void) const
{
	return this->_index;
}

std::string	Contact::get_firstname(void) const
{
	return this->_firstName;
}

std::string	Contact::get_lastname(void) const
{
	return this->_lastName;
}

std::string	Contact::get_nickname(void) const
{
	return this->_nickName;
}

std::string	Contact::get_phonenumber(void) const
{

	return this->_phoneNumber;
}

std::string	Contact::get_darkestsecret(void) const
{
	return this->_darkestSecret;
}

/*
functions
*/

static std::string	read_value(std::string output)
{

}
void	init(int index)
{
	std::cout << "Adding new contact for the index " << index << std::endl;
	std::cout << "Please fill in the following informations:" << std::endl;
	this->_firstName = read_value("First name: ");
	this->_lastName = read_value("Last name: ");
	this->_nickName = read_value("Nick name: ");
	this->_phoneNumber = read_value("Phone number: ");
	this->_darkestSecret = read_value("Darkest secret: ");
	std::cout << "Successfully added contact!\n" << std::endl;
}
