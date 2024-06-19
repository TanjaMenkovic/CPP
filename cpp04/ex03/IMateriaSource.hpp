/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:44:33 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:44:34 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include	<string>
#include	<iostream>
#include	"AMateria.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {}
		virtual void learnMateria(AMateria* materia) = 0;
		virtual AMateria* createMateria(const string& type) = 0;
};
