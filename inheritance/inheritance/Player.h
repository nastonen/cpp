#pragma once

#include "Person.h"
#include <string_view>

class Player : public Person
{
	friend std::ostream& operator<<(std::ostream& out, const Player& player);

public:
	Player();
	Player(std::string_view full_name, int age, std::string_view address, double salary);
	Player(const Player& src);
	~Player();

	void play()
	{
		full_name = "John Snow";
		age = 28;
	}

private:
	int career_start_year{ 0 };
	double salary{ 0.0 };
	int health_factor{ 0 };
};
