/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:40:31 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/05/28 13:40:33 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>
# include <iomanip>

class Contact {
	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		~Contact();
		
		void		Contact::set_index(int index);
		int			Contact::get_index(void) const;
		std::string	Contact::get_firstname(void) const;
		std::string	Contact::get_lastname(void) const;
		std::string	Contact::get_nickname(void) const;
		std::string	Contact::get_phonenumber(void) const;
		std::string	Contact::get_darkestsecret(void) const;

		void		init(int index);
}

#endif
