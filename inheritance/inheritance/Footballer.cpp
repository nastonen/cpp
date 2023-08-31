#include "Footballer.h"

Footballer::Footballer()
{
	std::cout << "Default ctor for Footballer called..." << std::endl;
}

Footballer::Footballer(std::string_view full_name, int age, std::string_view address, double salary, int goal_cnt)
	: Player(full_name, age, address, salary), goal_cnt(goal_cnt)
{
	std::cout << "Custom ctor for Footballer called..." << std::endl;
}

Footballer::Footballer(const Footballer& src)
	: Player(src), goal_cnt(src.goal_cnt)
{
	std::cout << "Custom copy ctor for Footballer called..." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Footballer& f)
{
	out << "Footballer [" << f.get_full_name() << " " << f.get_age() << " " << f.get_address() << "]";
	return out;
}

Footballer::~Footballer()
{
}
