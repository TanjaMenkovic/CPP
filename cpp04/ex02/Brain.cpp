/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:09:45 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/17 18:09:46 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	cout << "You finally got a brain! :)" << endl;
}

Brain::Brain(const Brain &copy)
{
	cout << "Brain Copy Constructor called" << endl;
	*this = copy;
}

Brain::~Brain()
{
	cout << "You don't have brain anymore :(" << endl;
}

Brain &Brain::operator=(const Brain &src)
{
	cout << "Brain Assignation operator called" << endl;
	if (this == &src)
		return *this;
	for (int i = 0; i < 100; i++)
	{
		if (src._ideas[i].length() > 0)
			this->_ideas[i].assign(src._ideas[i]);
	}
	return *this;
}

const string	Brain::getIdea(size_t i) const
{
	if (i < 100)
		return(this->_ideas[i]);
	else
		return ("\033[33mBrain can't think about more than 100 ideas at the same time :(((\033[0m");
}

const string *Brain::getIdeaAddress(size_t i)const
{
	if (i < 100)
	{
		const string	&stringREF = this->_ideas[i];
		return(&stringREF);
	}
	else
		return (NULL);
}

void	Brain::setIdea(size_t i, string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		cout << "\033[33mBrain can't think about more than 100 ideas at the same time :(((\033[0m" << endl;
}
