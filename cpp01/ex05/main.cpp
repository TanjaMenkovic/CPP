/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:46:26 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:18:26 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    std::string  input;
    Harl    harl;

    std::cout << "\n\nPick what kind of complain you want Harl to do.\n" << std::endl;
    std::cout << "Your options are:\nDEBUG\nINFO\nWARNING\nERROR\n" << std::endl;

    while (1)
    {
        std::cout << "Harl is compalining about..." << std::endl;
        getline(std::cin, input);
        if (std::cin.eof() == true)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << std::endl;
        }
        if (input.empty())
            std::cout << "Please insert one of offered values." << std::endl;
        else
        {
            harl.complain(input);
            std::cout << std::endl;
            if (getLevel(input) != -1)
                break ;
        }
    }

    return 0;
}