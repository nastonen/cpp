#include "dog.h"
#include <iostream>

namespace Animal
{
	Dog::Dog(int age, const std::string& name, const std::string& breed)
		: m_age{ new int(age) }, m_name{ name }, m_breed{ breed }, m_cat{ new Cat }
	{
		//this->m_name = name;
		//this->m_breed = breed;
		//this->m_age = age;
		++m_count;
		++m_count_inline;
	}

	// copy constructor
	Dog::Dog(const Dog& src) : Dog(src.age(), src.name(), src.breed())
	{
		std::cout << "Copy constructor called for " << this->m_name << std::endl;
	}

	// move constructor
	Dog::Dog(Dog&& src) noexcept
		: m_age{ src.steal_age() }, m_name{ std::move(src.name()) }, m_breed{ std::move(src.breed()) }
	{
		++m_count;
		++m_count_inline;
		std::cout << "Move ctor called for " << this->m_name << std::endl;
	}

	Dog::Dog() : Dog(0, "", "")
	{

	}

	Dog::~Dog()
	{
		//std::cout << "destr " << this->m_name << " of age " << *this->m_age << std::endl;
		delete this->m_age;
		--m_count;
		--m_count_inline;
	}

	void Dog::name(std::string name)
	{
		m_name = name;
	}
	const std::string& Dog::name() const
	{
		return m_name;
	}

	void Dog::breed(std::string breed)
	{
		m_breed = breed;
	}
	const std::string& Dog::breed() const
	{
		return m_breed;
	}

	void Dog::age(int age)
	{
		m_age = new int;
		*m_age = age;
	}
	const int& Dog::age() const
	{
		return *m_age;
	}
	int* Dog::steal_age()
	{
		int* new_age = this->m_age;
		this->m_age = nullptr;
		return new_age;
	}

	size_t Dog::m_count {0};

	/*Dog* Dog::setName(std::string_view name)
	{
		this->name = name;
		return this;
	}
	std::string_view Dog::getName() const
	{
		return this->name;
	}


	Dog* Dog::setBreed(std::string_view breed)
	{
		this->breed = breed;
		return this;
	}
	std::string_view Dog::getBreed() const
	{
		return this->breed;
	}

	Dog* Dog::setAge(int age)
	{
		this->age = new int;
		*(this->age) = age;
		return this;
	}
	int Dog::getAge() const
	{
		return *(this->age);
	}*/
}
