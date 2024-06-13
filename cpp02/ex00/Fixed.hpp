/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:38:28 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 14:38:29 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

using std::cout;
using std::endl;

class Fixed {
	private:
		int					_value;
		static const int	_bits = 8;

	public:
		Fixed(void); // default constructor
		Fixed(const Fixed &to_copy); // copy constructor
		~Fixed(void); //destructor

		Fixed &operator=(const Fixed &original); // copy assignment operator overload

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
