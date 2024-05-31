/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:21:42 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/05/30 18:56:04 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string	reading_options()
{
	std::string	input = "";
	int			success = 0;

	do
	{
		std::cout << "Please pick one of available options and tell us" << std::endl;
		std::cout << "what would you like to do?: " << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (std::cin.good() && !input.empty())
			success = 1;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input, please try again..." << std::endl;
		}
	} while (!success);
	
	std::cout << std::endl;
	std::cout << "-----------------------------------------------------\n" << std::endl;

	return (input);
}

int	main(void)
{
	std::string	input;
	int			input_len;
	PhoneBook	pb;

	std::cout <<"\n\n" << std::endl;
	std::cout << "PHONEBOOK:\n" << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "-----------------------------------------------------\n" << std::endl;
	std::cout << "Available phonebook options are:\n" << std::endl;
	std::cout << "ADD - add a new contact to your phone book." << std::endl;
	std::cout << "SEARCH - search for a specific contact inside of your phone book." << std::endl;
	std::cout << "EXIT - exit the program." << std::endl;
	std::cout << "Thanks fou using my PhoneBook!\n" << std::endl;
	std::cout << "-----------------------------------------------------\n" << std::endl;

	while (1)
	{
		input = reading_options();
		input_len = input.length();
		if (input_len == 3 && input.compare("ADD") == 0)
		{
			pb.add_contact();
			std::cout << "\n-----------------------------------------------------\n" << std::endl;
			continue;
		}
		else if (input_len == 6 && input.compare("SEARCH") == 0)
		{
			if (pb.display_contacts())
				pb.search_contact();
			std::cout << "\n-----------------------------------------------------\n" << std::endl;
			continue ;
		}
		else if (input_len == 4 && input.compare("EXIT") == 0)
			break ;
		else
		{
			std::cout << "Option doesn't exist, please try again...\n" << std::endl;
			std::cout << "-----------------------------------------------------\n" << std::endl;
		}
	}
	return (0);
}
