#include "Circle.h"

void draw_shape(const Shape& sh)
{
	sh.draw();
}

int main()
{
	//draw_shape(Shape("Shape1"));
	//draw_shape(Oval(2.0, 3.5, "Oval1"));
	//draw_shape(Circle(3.3, "Circle1"));

	/*Shape shape1("Shape");
	Oval oval1(2.0, 3.5, "Oval");
	Circle circle1(3.3, "Circle");

	Shape shape2 = circle1;*/

	/*Circle c1(7.2, "circle1");
	Oval o1(13.3, 1.2, "oval1");
	Circle c2(11.2, "circle2");
	Oval o2(12.2, 5.1, "oval2");
	Circle c3(5.2, "circle3");
	Oval o3(9.2, 6.7, "oval3");

	std::shared_ptr<Shape> shapes[]{ std::make_shared<Circle>(c1), std::make_shared<Oval>(o1) };
	for (auto& s : shapes) {
		s->draw(44);
	}*/

	Shape *s = new Oval();
	Oval* o = dynamic_cast<Oval*>(s);

	if (o) {
		o->do_ovaly_thingy();
	} else {
		std::cout << "Couldn't cast Shape to Oval" << std::endl;
	}

	std::cout << o->perimeter() << std::endl;

	std::cout << *s;

	try {
		if (1 != 2)
			//throw std::out_of_range("Fuck you");
			throw std::logic_error("asdf");
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
