/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:51:58 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 10:52:02 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <iomanip>
# include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

class Harl {
	private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

	public:
		void complain(string level);
};

int  getLevel(string level);

#endif
