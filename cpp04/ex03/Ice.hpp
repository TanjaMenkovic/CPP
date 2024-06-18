/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:44:51 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:44:53 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& ice);
		~Ice(void);
		Ice& operator=(const Ice& ice);
        
		AMateria* clone(void) const;
		void use(ICharacter& target);
};
