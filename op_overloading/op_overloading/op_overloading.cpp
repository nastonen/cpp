#include <iostream>
#include "Point.h"

int main()
{
	Point p1{ 10, 10 };
	Point p2{ 20, 20 };

	Point p3 = p1 + p2;
	Point p4{ operator+(p1, p2) };

	//p3.print_info();

	//p1[0] = 100;
	//p1[1] = 200;
	//std::cout << "x: " << p1[0] << ", y: " << p1[1] << std::endl;
	//std::cout << p1;

	const Point p5{ 1, 2 };
	//std::cout << p5[0] << std::endl;
	std::cout << p1 << p5;

	//Point p6;
	//std::cin >> p6;
	//std::cout << p6;

	//std::cout << (p1 += p2);

	++p1;
	p1++;
	std::cout << static_cast<double>(p1) << std::endl;

	p3 = p1;
	//p1.set_data(55);
	std::cout << p3 << std::endl;
	//p3.set_data(66);
	std::cout << p3 << std::endl;

	Point p22 = p2 = p3;

	Point p11(10, 10);
	Point p33(30, 30);
	std::cout << std::boolalpha << (p11 != p33) << std::endl;
	std::cout << std::boolalpha << (p11 >= p33) << std::endl;
}
