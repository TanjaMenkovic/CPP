/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:46:26 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 08:46:28 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    string  input;
    Harl    harl;

    cout << "\n\nPick what kind of complain you want Harl to do.\n" << endl;
    cout << "Your options are:\nDEBUG\nINFO\nWARNING\nERROR\n" << endl;

    while (1)
    {
        cout << "Harl is compalining about..." << endl;
        getline(cin, input);
        if (cin.eof() == true)
        {
            cin.clear();
            clearerr(stdin);
            cout << endl;
        }
        if (input.empty())
            cout << "Please insert one of offered values." << endl;
        else
        {
            harl.complain(input);
            cout << endl;
            if (getLevel(input) != -1)
                break ;
        }
    }

    return 0;
}