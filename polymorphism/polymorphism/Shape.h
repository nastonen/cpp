#pragma once

#include <string>
#include <iostream>
#include <string_view>
#include "Stream_insertable.h"

class Shape : public StreamInsertable
{
public:
	inline static int cnt{ 0 };

	Shape() = default;
	Shape(std::string_view descr) : descr(descr) {};
	Shape(std::string_view descr, double x_radius, double y_radius)
		: descr(descr), x_radius(x_radius), y_radius(y_radius)
	{
		++cnt;
	}
	~Shape()
	{
		std::cout << "Destr for Shape is called" << std::endl;
	};

	virtual void draw() const
	{
		std::cout << "Shape::draw() called. Drawing " << descr << std::endl;
	}

	virtual void draw(int i) const
	{
		std::cout << "Shape::draw() with param " << i << " called. Drawing " << descr << std::endl;
	}

	virtual double perimeter() const = 0;

	void stream_insert(std::ostream& out) const override
	{
		out << "Shape. Descr: " << descr << ", x_radius: " << x_radius << ", y_radius: " << y_radius << std::endl;
	}

	virtual int get_cnt() const
	{
		return cnt;
	}

protected:
	std::string_view descr;
	double x_radius{ 0.0 };
	double y_radius{ 0.0 };
};
