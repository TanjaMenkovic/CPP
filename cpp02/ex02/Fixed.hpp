/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:02:36 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:02:38 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Fixed {
	private:
		int					_value;
		static const int	_bits = 8;

		static int customRound(float value); // Custom rounding function

	public:
		Fixed(void); // default constructor
		
		// parametrized constructors
		Fixed(const int inInt);
		Fixed(const float inFloat);

		Fixed(const Fixed &to_copy); // copy constructor
		~Fixed(void); //destructor

		Fixed &operator=(const Fixed &original); // copy assignment operator overload

		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int	toInt(void) const;

		bool operator>(const Fixed &nbr);
        	bool operator<(const Fixed &nbr);
        	bool operator<=(const Fixed &nbr);
       		bool operator>=(const Fixed &nbr);
        	bool operator==(const Fixed &nbr);
        	bool operator!=(const Fixed &nbr);
        	Fixed operator+(const Fixed &nbr);
        	Fixed operator-(const Fixed &nbr);
        	Fixed operator*(const Fixed &nbr);
		Fixed operator/(const Fixed &nbr);
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};

ostream &operator<<(ostream &stream, const Fixed &nbr);

#endif
