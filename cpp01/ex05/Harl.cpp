/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:46:09 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 08:46:11 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << endl;
}

void Harl::info(void)
{
	cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << endl;
}

void Harl::warning(void)
{
	cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << endl;
}

void Harl::error(void)
{
	cout << "This is unacceptable! I want to speak to the manager now." << endl;
}

int  getLevel(string level)
{
    const string    levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return i;
    }
    return -1;
}

void Harl::complain(string level)
{
	if (level.empty())
	{
		cerr << "Empty log level, can't log. Harl is being quiet." << endl;
		return ;
	}

    int levelNum = getLevel(level);
    if (levelNum == -1)
    {
	    cerr << "Could not find that compalint. Please try again."<< endl;
        return ;
    }

    // pointers to private functions
    void (Harl::*complain_f[4])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

    for (int i = 0; i < 4; i++)
    {
        (this->*complain_f[i])();
        return ;
    }
}
