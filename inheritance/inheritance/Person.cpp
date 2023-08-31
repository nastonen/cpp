#include "Person.h"

Person::Person()
{
	std::cout << "Default ctor for Person called..." << std::endl;
}

Person::Person(std::string_view full_name, int age, std::string_view address)
	: full_name(full_name), age(age), address(address)
{
	std::cout << "Custom ctor for Person called..." << std::endl;
}

Person::Person(const Person& src)
	: full_name(src.full_name), age(src.age), address(src.address)
{
	std::cout << "Custom copy ctor for Person called..." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Person& person)
{
	out << "Person [" << person.get_full_name() << " " << person.get_age() << " " << person.get_address() << "]";
	return out;
}

Person::~Person()
{
}
