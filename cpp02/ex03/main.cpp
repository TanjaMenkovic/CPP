#include <iostream>
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	const Point a(0, 0);
	const Point b(20, 0);
	const Point c(10, 30);
	const Point w = c;
	const Point point1(10, 15);

	cout << "\n------------TEST 1-----------\n" << endl;
	if (bsp(a, b, w, point1) == true)
		cout << "Point is inside!" << endl;
	else
		cout << "Point is not inside!" << endl;
	cout << "\n-----------------------------\n" << endl;

	const Point d(-1.5, -1.5);
	const Point e(2.5, 2.5);
	const Point f(-1, -2);
	const Point point2(8.5, -9);

	cout << "\n------------TEST 2-----------\n" << endl;
	if (bsp(d, e, f, point2) == true)
		cout << "Point is inside!" << endl;
	else
		cout << "Point is not inside!" << endl;
	cout << "\n-----------------------------\n" << endl;

	const Point g(0, 0);
	const Point h(10, 30);
	const Point i(20, 0);
	const Point point3(10, 15);

	cout << "\n------------TEST 3-----------\n" << endl;
	if (bsp(g, h, i, point3) == true)
		cout << "Point is inside!" << endl;
	else
		cout << "Point is not inside!" << endl;
	cout << "\n-----------------------------\n" << endl;

	Point j(2.0, 1.0);
	Point k(10.0, 10.0);
	Point l(15.0, 8.0);
	Point point4(5.0, 5.0);

	cout << "\n------------TEST 4-----------\n" << endl;
	if (bsp(j, k, l, point4) == true)
		cout << "Point is inside!" << endl;
	else
		cout << "Point is not inside!" << endl;
	cout << "\n-----------------------------\n" << endl;

	return 0;
}
