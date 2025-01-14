/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:02:46 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:50:31 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

/*
static void	test_bool_operator(bool result, const std::string true_msg,  const std::string false_msg)
{
	if (result)
	{
		std::cout << true_msg << std::endl;
	}
	else
	{
		std::cout << false_msg << std::endl;
	}
}*/

int main(void) {
/*	Fixed a;
	Fixed lhs = Fixed(5.05f);
	Fixed rhs = Fixed(2);
	Fixed b(lhs * rhs);

	Fixed c(lhs + rhs);
	std::cout << c << std::endl;
	Fixed d(lhs / rhs);
	std::cout << d << std::endl;
	Fixed e(lhs - rhs);
	std::cout << e << std::endl;
	Fixed f(lhs * rhs);
	std::cout << f << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	test_bool_operator(a == b, "b is c!", "b is not c!");
	test_bool_operator(a != b, "a is not b!", "a is b!");
	test_bool_operator(a < b, "a is smaller than b!", "a is not smaller than b!");
	test_bool_operator(a > b, "a is bigger than b!", "a is not bigger than b!"); */

	Fixed a;
	
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
