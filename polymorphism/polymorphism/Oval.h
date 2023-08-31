#pragma once

#include "Shape.h"
#include <numbers>

class Oval : public Shape
{
public:
	inline static int cnt{ 0 };

	Oval() = default;
	Oval(double x_radius, double y_radius, std::string_view descr)
		: Shape(descr, x_radius, y_radius)
	{
		++cnt;
	}
	~Oval()
	{
		std::cout << "Destr for Oval is called" << std::endl;
	}

	void draw() const override
	{
		std::cout << "Oval::draw() called. Drawing " << descr << " with x_radius: " << x_radius
			<< " and y_radius: " << y_radius << std::endl;
	}

	int get_cnt() const override
	{
		return cnt;
	}

	double perimeter() const override
	{
		return std::numbers::pi * 2;
	}

	void stream_insert(std::ostream& out) const override
	{
		out << "Oval. Descr: " << descr << ", x_radius: " << x_radius << ", y_radius: " << y_radius << std::endl;
	}

	void do_ovaly_thingy()
	{
		std::cout << "Doing Ovaly thingy that only Ovals do" << std::endl;
	}
};
