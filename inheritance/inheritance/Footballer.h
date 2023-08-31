#pragma once

#include "Player.h"

class Footballer : public Player
{
	friend std::ostream& operator<<(std::ostream& out, const Footballer& player);

public:
	Footballer();
	Footballer(std::string_view full_name, int age, std::string_view address, double salary, int goal_cnt);
	Footballer(const Footballer& src);
	~Footballer();

private:
	int goal_cnt;
};
