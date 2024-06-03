/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:51:27 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 10:51:28 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;
    string  input;
    int     lvl;

    if (argc != 2)
    {
        cerr << "You need to give an argument!\n" << endl;
        return 1;
    }
    if (argv[1] && argv[1][0] == '\0')
	{
		cerr << "[ Probably complaining about insignificant problems ]" << endl;
		return 1;
	}

    input = (string)argv[1];
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
