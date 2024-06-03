/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:42:42 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 08:42:43 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int	main(void)
{
	int	i;
	int	N;
	string	zombies_name;
	Zombie	*zombie_army;

	while (1)
    	{
        	cout << "\n\nName the Zombies: ";
        	getline(cin, zombies_name);
        	if (cin.eof() == true)
        	{
            		cin.clear();
            		clearerr(stdin);
				cout << endl;
        	}
        	if (!zombies_name.empty())
            		break ;
        	cout << "Please insert a name for the zombies" << endl;
    	}

	cout << "\n\nHow many zombies would you like to have?" << endl;
	if (cin >> N)
		cout << "You have " << N << " zombies.\n" << endl;
	else
	{
		cout << "Invalid input! Please enter an integer!\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	zombie_army = zombieHorde(N, zombies_name);

	cout << "---------------------------------------\n" << endl;

	for (i = 0; i < N; i++)
		zombie_army[i].announce();

	cout << "\n---------------------------------------\n" << endl;
	delete[] zombie_army;

	return 0;
}
