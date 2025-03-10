/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:51:58 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:19:29 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <iomanip>
# include <string>

class Harl {
	private:
                void debug();
                void info();
                void warning();
                void error();

	public:
		void complain(std::string level);
};

int  getLevel(std::string level);

#endif
