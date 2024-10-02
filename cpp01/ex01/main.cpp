/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:42:42 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:05:41 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <limits>  // Needed for std::numeric_limits

int main(void)
{
    int i;
    int N;
    std::string zombies_name;
    Zombie *zombie_army;

    while (1)
    {
        std::cout << "\n\nName the Zombies: ";
        getline(std::cin, zombies_name);
        if (std::cin.eof() == true)
        {
            std::cin.clear();  // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the rest of the input
            std::cout << std::endl;
        }
        if (!zombies_name.empty())
            break;
        std::cout << "Please insert a name for the zombies" << std::endl;
    }

    std::cout << "\n\nHow many zombies would you like to have?" << std::endl;
    if (std::cin >> N)
        std::cout << "You have " << N << " zombies.\n" << std::endl;
    else
    {
        std::cout << "Invalid input! Please enter an integer!\n" << std::endl;
        std::cin.clear();  // Clear error flags after invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore leftover invalid input
        return 1;  // Exit if invalid input is given
    }

    zombie_army = zombieHorde(N, zombies_name);

    std::cout << "---------------------------------------\n" << std::endl;

    for (i = 0; i < N; i++)
        zombie_army[i].announce();

    std::cout << "\n---------------------------------------\n" << std::endl;
    delete[] zombie_army;

    return 0;
}
