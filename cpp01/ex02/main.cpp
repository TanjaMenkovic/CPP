/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:42:02 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 08:42:04 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

int main(void)
{
	string brain = "HI THIS IS BRAIN";
	string *stringPTR = &brain;
	string &stringREF = brain;

	cout << "Memory address of the string variable:\t" << &brain << endl;
	cout << "Memory address held by stringPTR:\t" << stringPTR << endl;
	cout << "Memory address held by stringREF:\t" << &stringREF << endl;

	cout << "\nValue of the string variable:\t" << brain << endl;
	cout << "Value pointed to by stringPTR:\t" << *stringPTR << endl;
	cout << "Value pointed to by stringREF:\t" << stringREF << endl;

	return 0;
}
