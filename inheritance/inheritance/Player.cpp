#include "Player.h"

Player::Player()
{
	std::cout << "Default ctor for Player called..." << std::endl;
}

Player::Player(std::string_view full_name, int age, std::string_view address, double salary)
	: Person(full_name, age, address), salary(salary)
{
	std::cout << "Custom ctor for Player called..." << std::endl;
}

Player::Player(const Player& src)
	: Person(src), salary(src.salary)
{
	std::cout << "Custom copy ctor for Player called..." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << "Player [" << player.full_name << " " << player.age << " " << player.get_address() << "]";
	return out;
}

Player::~Player()
{
}
