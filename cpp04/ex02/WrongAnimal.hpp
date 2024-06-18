/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:05 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/17 17:11:07 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class WrongAnimal
{
	protected:
		string _type;

	public:
		WrongAnimal();
        WrongAnimal(string name);
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &src);

		virtual void makeSound(void) const;
		string getType(void) const;
};
