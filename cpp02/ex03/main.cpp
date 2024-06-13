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

// bool	bsp(Point const a, Point const b, Point const c, Point const point);

/*

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(10, 2)
Output: Inside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(20,0) 

Input: A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
Output: Outside
Explanation:
              B(10,30)
                / \
               /   \
              /     \
             /       \      P
            /         \
     A(0,0) ----------- C(20,0) 

Solution: 
Let the coordinates of three corners be (x1, y1), (x2, y2) and (x3, y3). And coordinates of the given point P be (x, y)

Calculate area of the given triangle, i.e., area of the triangle ABC in the above diagram. 
Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2) ] / 2 
Calculate area of the triangle PAB. We can use the same formula for this. Let this area be A1. 
Calculate area of the triangle PBC. Let this area be A2. 
Calculate area of the triangle PAC. Let this area be A3. 
If P lies inside the triangle, then A1 + A2 + A3 must be equal to A. 

*/

int main(void)
{
    cout << "Is (30, 15) inside of triangle: (0, 0) (10, 30) (20, 0)?" << endl;
	if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15) ) == true ) {
        cout << "Point is in the triangle\n" << endl;
    } else {
        cout << "Point is not in the triangle\n" << endl;
    }

    cout << "Is (10, 2) inside of triangle: (0, 0) (10, 30) (20, 0)?" << endl;
	if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 2) ) == true ) {
        cout << "Point is in the triangle\n" << endl;
    } else {
        cout << "Point is not in the triangle\n" << endl;
    }

	return 0;
}
