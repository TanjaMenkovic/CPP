/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:42:31 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 08:42:34 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <iomanip>
# include <string>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();

		void setName(std::string name);
		const std::string& getName(void) const;

		void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
