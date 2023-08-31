#pragma once

#include <string>
#include <iostream>
#include <string_view>

class Person
{
	friend std::ostream& operator<<(std::ostream& out, const Person& person);

public:
	std::string full_name{ "None" };

	Person();
	Person(std::string_view full_name, int age, std::string_view address);
	Person(const Person& src);
	~Person();

	// getters
	std::string get_full_name() const
	{
		return full_name;
	}

	int get_age() const
	{
		return age;
	}

	std::string get_address() const
	{
		return address;
	}

protected:
	int age{ 0 };

private:
	std::string address{ "None" };
};
