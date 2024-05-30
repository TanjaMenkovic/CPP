/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:40:16 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/05/28 14:33:06 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iostream>

class PhoneBook {
	private:
		Contact	_contacts[8];

	public:
		PhoneBook();
		~PhoneBook();

		void	add_contact(void);
		void	search_contact(void) const;
		int		display_contacts(void) const;
};

#endif
