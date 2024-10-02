/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:41:07 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:01:56 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    std::string input;
    Zombie *new_zombie;

    std::cout << "\n\nCreating a zombie on the heap:\n" << std::endl;
    std::cout << "Name the heap Zombie: ";
    getline(std::cin, input);

    if (std::cin.eof() == true)
    {
        std::cin.clear(); // Clear the error flags
        std::cin.ignore(); // Ignore the leftover input
        std::cout << std::endl;
    }

    new_zombie = newZombie(input);
    new_zombie->announce();
    delete new_zombie;

    std::cout << "\n----------------------------------\n" << std::endl;

    std::cout << "Creating a zombie on the stack:\n" << std::endl;
    getline(std::cin, input);

    if (std::cin.eof() == true)
    {
        std::cin.clear(); // Clear the error flags
        std::cin.ignore(); // Ignore the leftover input
        std::cout << std::endl;
    }

    randomChump(input);

    return 0;
}

