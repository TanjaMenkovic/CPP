/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:20:21 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 10:48:40 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
destructor
*/
Contact::~Contact() {}

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
int		Contact::get_index(void) const
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
	int			success = 0;
	std::string	input = "";

	do {
		std::cout << output << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "EOF reached!" << std::endl;
			exit(0);
		}
		if (std::cin.good() && !input.empty())
			success = 1;
		else if (input.empty())
		{
			std::cin.clear();
			std::cout << std::endl;
			std::cout << "You entered an empty string! Please try again!" << std::endl;
		}
		else
		{
			std::cin.clear();
			std::cout << std::endl;
			std::cout << "Invalid input! Please try again!" << std::endl;
		}
	} while (!success);
	return (input);
}

void	Contact::init(int index)
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

static std::string	check_max(std::string output)
{
	if (output.length() > 10)
		return output.substr(0, 9) + '.';
	return output;
}

void	Contact::display(void) const
{
	if (this->_index == -1)
		return ;
	std::cout << "|" << std::setw(10) << this->_index << std::flush;
	std::cout << "|" << std::setw(10) << check_max(this->_firstName) << std::flush;
	std::cout << "|" << std::setw(10) << check_max(this->_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << check_max(this->_nickName) << std::flush;
	std::cout << "|" << std::flush;
	std::cout << std::endl;
}

void	Contact::view(void) const
{
	if (this->_index == -1)
	{
		std::cout << "Index not available! Add new contacts!" << std::endl;
		return;
	}

	std::cout << "CONTACT #" << this->_index << std::endl;
	std::cout << "First name:\t" << this->_firstName << std::endl;
	std::cout << "Last name:\t" << this->_lastName << std::endl;
	std::cout << "Nickname:\t" << this->_nickName << std::endl;
	std::cout << "Phone number:\t" << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret:\t" << this->_darkestSecret << "\n" << std::endl;
}
