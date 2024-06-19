/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:45:24 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:45:26 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

#define N_MATERIAS	4

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_materias [N_MATERIAS];
		short int	_currIdx;
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& materiaSource);
		~MateriaSource(void);
		MateriaSource&	operator=(const MateriaSource& materiaSource);
		void			learnMateria(AMateria* materia);
		AMateria*		createMateria(const std::string& type);
};