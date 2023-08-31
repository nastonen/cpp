#pragma once

#include <iostream>
#include <cassert>

class Point
{
friend Point operator+ (Point& left, Point& right);
friend std::ostream& operator<< (std::ostream& os, const Point& p);
friend std::istream& operator>> (std::istream& is, Point& p);
friend Point& operator+= (Point& left, const Point& right);

public:
	Point() = default;
	Point(double x, double y/*, int data*/) : m_x(x), m_y(y)/*, p_data(new int(data))*/ {}
	~Point() = default;

	/*void set_data(int data)
	{
		*p_data = data;
	}*/

	// copy ctor
	Point(const Point& p)
	{
		std::cout << "Copy ctor called" << std::endl;

		if (this != &p) {
			m_x = p.m_x;
			m_y = p.m_y;

			//delete p_data;
			//p_data = new int(*p.p_data);
		}
	}

	// copy assignment
	Point& operator=(const Point& p)
	{
		std::cout << "Copy assignment operator called" << std::endl;

		if (this != &p) {
			m_x = p.m_x;
			m_y = p.m_y;
			
			//delete p_data;
			//p_data = new int(*p.p_data);
		}

		return *this;
	}

	/*	default C++20 operator==
		also generates operator!= automatically
	*/
	//bool operator==(const Point& right_operand) const = default;

	/*/bool operator==(const Point& other) const
	{
		return this->length() == other.length();
	}*/

	// generated automatically
	/*bool operator!=(const Point& other) const
	{
		return this->length() != other.length();
	}*/

	/* default C++20 comparison operator */
	auto operator<=>(const Point& right_operand) const = default;

	/*auto operator<=>(const Point& right) const
	{
		if (length() > right.length())
			return std::partial_ordering::greater;
		else if (length() == right.length())
			return std::partial_ordering::equivalent;
		if (length() < right.length())
			return std::partial_ordering::less;
		else
			return std::partial_ordering::unordered;
	}*/

	// all generated automatically

	/*bool operator>(const Point& other) const
	{
		return this->length() > other.length();
	}

	bool operator<(const Point& other) const
	{
		return this->length() < other.length();
	}

	bool operator>=(const Point& other) const
	{
		return this->length() >= other.length();
	}

	bool operator<=(const Point& other) const
	{
		return this->length() <= other.length();
	}*/

	Point operator+(const Point& right) const
	{
		return Point(this->m_x + right.m_x, this->m_y + right.m_y/*, 1*/);
	}

	void print_info()
	{
		std::cout << "Point [x: " << m_x << ", y: " << m_y << "]" << std::endl;
	}

	double& operator[](size_t index)
	{
		assert(index == 0 || index == 1);
		return (index == 0) ? m_x : m_y;
	}

	const double& operator[](size_t index) const
	{
		assert(index == 0 || index == 1);
		return (index == 0) ? m_x : m_y;
	}

	// prefix
	void operator++()
	{
		++m_x;
		++m_y;
	}

	// postfix
	Point operator++(int)
	{
		Point local_copy(*this);
		++(*this);
		return local_copy;
	}

	// type conversion
	explicit operator double() const
	{
		std::cout << "Using type conversion from Point to double" << std::endl;
		return static_cast<double>(m_x + m_y);
	}

private:
	double m_x{};
	double m_y{};
	//int* p_data;

	double length() const
	{
		return sqrt(pow(m_x - 0, 2) + pow(m_y - 0, 2) * 1.0);
	}
};

inline Point operator+ (Point& left, Point& right)
{
	return Point(left.m_x + right.m_x, left.m_y + right.m_y/*, 1*/);
}

inline Point& operator+= (Point& left, const Point& right)
{
	left.m_x += right.m_x;
	left.m_y += right.m_y;

	return left;
}

inline std::ostream& operator<< (std::ostream& os, const Point& p)
{
	os << "Point [x: " << p.m_x << ", y: " << p.m_y /* << ", p_data: " << *(p.p_data) << "]"*/ << std::endl;
	return os;
}

inline std::istream& operator>> (std::istream& is, Point& p)
{
	double x, y;

	std::cout << "Input 2 points separated by space: ";
	is >> x >> y;
	p.m_x = x;
	p.m_y = y;

	return is;
}
