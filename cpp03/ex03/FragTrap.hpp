/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:06:55 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:06:57 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(string name);
		FragTrap(const FragTrap &to_copy);
		FragTrap& operator=(const FragTrap &original);
		~FragTrap(void);

		void highFivesGuys(void);
};

#endif
