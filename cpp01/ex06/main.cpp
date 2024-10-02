/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:51:27 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:21:15 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;
    std::string  input;
    int     lvl;

    if (argc != 2)
    {
        std::cerr << "You need to give an argument!\n" << std::endl;
        return 1;
    }
    if (argv[1] && argv[1][0] == '\0')
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 1;
	}

    input = (std::string)argv[1];
    lvl = getLevel(input);
    switch (lvl)
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

    return 0;
}
