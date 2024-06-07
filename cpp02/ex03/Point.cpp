/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:03:21 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:03:23 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) 
{
}

Point::Point(const float x, const float y) : _x(x), _y(y) 
{
}

Point::Point(const Point &to_copy) 
{
	*this = to_copy;
}

Point& Point::operator=(const Point &original)
{
	(Fixed)this->_x = original.getX();
	(Fixed)this->_y = original.getY();
	return *this;
}

Point::~Point(void) 
{
}

Fixed Point::getX(void) const 
{
	return this->_x;
}

Fixed Point::getY(void) const 
{
	return this->_y;
}
