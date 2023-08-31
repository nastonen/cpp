#pragma once

#include "Oval.h"

class Circle final : public Oval
{
public:
    inline static int cnt{ 0 };

    Circle() = default;
    Circle(double radius, std::string_view descr)
        : Oval(radius, radius, descr)
    {
        ++cnt;
    }
    ~Circle()
    {
        std::cout << "Destr for Circle is called" << std::endl;
    }

    void draw() const final
    {
        std::cout << "Circle::draw() called. Drawing " << descr << " with radius: " << x_radius << std::endl;
    }

    int get_cnt() const final
    {
        return cnt;
    }
};
