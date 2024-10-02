/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:18 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:46:23 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Header-protection */
#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
        Animal(std::string name);
		Animal(const Animal &copy);
		virtual ~Animal();
		Animal &operator=(const Animal &src);

		virtual void makeSound(void) const = 0; // pure virtual function
		std::string getType(void) const;
};
