#pragma once

#include <string>
#include <iostream>

class dog
{
public:
	explicit dog(std::string name_param);
	dog(); // = default;
	~dog();

	void print_dog() const
	{
		std::cout << "Printing dog: " << dog_name << std::endl;
	}

	std::string get_name() const
	{
		return dog_name;
	}

	void set_dog_name(const std::string& name)
	{
		dog_name = name;
	}

	std::string dog_name{ "Puffy" };
};
