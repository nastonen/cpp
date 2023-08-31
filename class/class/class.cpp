#include "dog.h"
#include "point.h"
#include <iostream>

namespace Weigth
{
	double mult(double x, double y)
	{
		std::cout << "calling weight mult" << std::endl;
		return x * y - 1.0;
	}

	double div(double x, double y)
	{
		return x / y - 1.0;
	}

	namespace More
	{
		double mult(double x, double y)
		{
			std::cout << "calling weight::more mult" << std::endl;
			return x * y;
		}
	}
}

/*void Animal::debug_dog(const Animal::Dog& d)
{
	std::cout << d.m_name << " is a " << d.m_breed << " and " << *d.m_age << " years old." << std::endl;
}*/

int main()
{	
	Animal::Dog d1;
	d1.name("Fluffy");
	d1.breed("Shepperd");
	d1.age(4);

	{
		const Animal::Dog d2(d1);
	}

	Animal::Dog d3(std::move(Animal::Dog{ 1, "lol", "asdf" }));
	std::cout << d3.name() << " is " << d3.breed() << " and " << d3.age() << " years old." << std::endl;

	//Dog d4;
	//d4 = d1;

	//point p{ .x = 1, .z = 3 };
	//std::cout << p.x << " " <<  p.y << " " <<  p.z << std::endl;

	//std::cout << d4.name() << " is " << d4.breed() << " and " << d4.age() << " years old." << std::endl;
	//std::cout << d4.name() << " is " << d4.breed() << " and " << d4.age() << " years old." << std::endl;

	//Dog arr[] { d1, d2, Dog(d1) };

	//debug_dog(d1);
	point p{};
	//p.debug_dog(d1);

	std::cout << "cnt of dogs: " << Animal::Dog::m_count << std::endl;
	std::cout << "cnt of dogs (inline): " << Animal::Dog::m_count_inline << std::endl;

	std::cout << d1.m_cat->name << std::endl;

	Weigth::div(4.0, 55.1);

	Weigth::More::mult(1, 2);
	Weigth::mult(1, 2);
}
