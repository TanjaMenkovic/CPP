/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:45:03 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:45:10 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void): _currIdx(0)
{
	cout << "MateriaSource has been created" << endl;
	for (int i = 0; i < N_MATERIAS; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource): _currIdx(materiaSource._currIdx)
{
	cout << "MateriaSource: Copy constructor called" << endl;
	for (int i = 0; i < N_MATERIAS; i++)
	{
		if (materiaSource._materias[i] != NULL)
			this->_materias[i] = materiaSource._materias[i]->clone();
	}
}

MateriaSource::~MateriaSource(void)
{
	cout << "MateriaSource has beed destroyed at address " << this << endl;
	for (int i = 0; i < N_MATERIAS; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& materiaSource)
{
	cout << "MateriaSource: Copy constructor called" << endl;
	if (this != &materiaSource)
	{
		for (int i = 0; i < N_MATERIAS; i++)
		{
			if (this->_materias[i] != NULL)
				delete this->_materias[i];
			this->_materias[i] = NULL;
			if (materiaSource._materias[i] != NULL)
				this->_materias[i] = materiaSource._materias[i]->clone();
		}
		this->_currIdx = materiaSource._currIdx;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (this->_currIdx == -1)
	{
		if (materia != NULL)
			delete materia;
		return ;
	}
	for (int i = 0; i < N_MATERIAS; i++)
		if (this->_materias[i] == materia)
			return ;
	this->_materias[this->_currIdx] = materia;
	this->_currIdx = this->_currIdx + 1 >= N_MATERIAS ? -1 : this->_currIdx + 1;
}

AMateria*	MateriaSource::createMateria(const string& type)
{
	for (int i = 0; i < N_MATERIAS; i++)
	{
		if (this->_materias[i] != NULL)
		{
			if (this->_materias[i]->getType().compare(type) == 0)
				return (this->_materias[i]->clone());
		}
	}
	return (0);
}