/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:03:51 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:03:52 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed abs(Fixed x)
{
	return (x < 0) ? x * -1 : x;
}

/* Formula
	( x1*(y2 - y3) 
	+ x2*(y3 - y1) 
	+ x3*(y1 - y2) ) / 2
*/	

static Fixed triangleArea(Point const p1, Point const p2, Point const p3)
{
	return abs((p1.getX() * (p2.getY() - p3.getY())
		+ p2.getX() * (p3.getY() - p1.getY())
		+ p3.getX() * (p1.getY() - p2.getY())) / Fixed(2));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = triangleArea(a, b, c);
   	Fixed pbcArea = triangleArea(point, b, c);
    Fixed pacArea = triangleArea(point, c, a);
    Fixed pabArea = triangleArea(point, a, b);

	cout << "Area of partitioned triangles: " << pbcArea + pacArea + pabArea << endl;
	cout << "Area of original triangle: " << abcArea << endl;

	return (abs(abcArea - (pbcArea + pacArea + pabArea)) != Fixed(0.01f));
}
