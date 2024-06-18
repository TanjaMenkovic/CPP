/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:18 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/17 17:10:19 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Header-protection */
#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

class Animal
{
	protected:
		string _type;

	public:
		Animal();
        Animal(string name);
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &src);

		virtual void makeSound(void) const = 0; // pure virtual function
		string getType(void) const;
};
