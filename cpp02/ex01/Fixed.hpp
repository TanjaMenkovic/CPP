/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:01:57 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:26:46 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int			_value;
		static const int	_bits = 8;

		static int customRound(float value); // Custom rounding function

	public:
		Fixed(); // default constructor
		
		// parametrized constructors
		Fixed(const int inInt);
		Fixed(const float inFloat);

		Fixed(const Fixed &to_copy); // copy constructor
		~Fixed(); //destructor

		Fixed &operator=(const Fixed &original); // copy assignment operator overload

		int	getRawBits() const;
		void	setRawBits(int const raw);

		float	toFloat() const;
		int	toInt() const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);

#endif
