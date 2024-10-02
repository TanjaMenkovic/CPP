/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:03:12 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:51:58 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int					_value;
		static const int	_bits = 8;

		// Custom rounding function
		static int customRound(float value); 

	public:
		Fixed(); // default constructor
		
		// parametrized constructors
		Fixed(const int inInt);
		Fixed(const float inFloat);

		// copy constructor
		Fixed(const Fixed &to_copy);
		//destructor
		~Fixed(); 

		// copy assignment operator overload
		Fixed &operator=(const Fixed &original); 

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int	toInt(void) const;

		bool operator>(const Fixed &nbr) const;
        bool operator<(const Fixed &nbr) const;
        bool operator<=(const Fixed &nbr) const;
       	bool operator>=(const Fixed &nbr) const;
        bool operator==(const Fixed &nbr) const;
        bool operator!=(const Fixed &nbr) const;
        Fixed operator+(const Fixed &nbr) const;
        Fixed operator-(const Fixed &nbr) const;
        Fixed operator*(const Fixed &nbr) const;
		Fixed operator/(const Fixed &nbr) const;
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);

#endif
