/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:38:28 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:23:12 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_bits = 8;

	public:
		Fixed(); // default constructor
		Fixed(const Fixed &to_copy); // copy constructor
		~Fixed(); //destructor

		Fixed &operator=(const Fixed &original); // copy assignment operator overload

		int	getRawBits() const;
		void	setRawBits(int const raw);
};

#endif
