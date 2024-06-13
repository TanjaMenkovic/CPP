/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:03:38 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:03:41 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	if ( bsp( Point(1, 1), Point(10, 30), Point(20, 0), Point(30, 15) ) == true ) {
        cout << "Point is in the triangle\n" << endl;
    } else {
        cout << "Point is not in the triangle\n" << endl;
    }

	if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 2) ) == true ) {
        cout << "Point is in the triangle\n" << endl;
    } else {
        cout << "Point is not in the triangle\n" << endl;
    }

	return 0;
}
