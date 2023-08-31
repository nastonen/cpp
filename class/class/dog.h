#pragma once

#include <string>
#include "cat.h"

struct point;

namespace Animal
{
	class Dog
	{
	private:
		int* m_age {};
		std::string m_name {};
		std::string m_breed {};

	public:
		Cat* m_cat;

		Dog(); // = default;
		explicit Dog(int age, const std::string& name = "Bobik", const std::string& breed = "Dvornaga");
		// copy constructor
		Dog(const Dog& src);
		// move constructor
		Dog(Dog&& src) noexcept;
		// destructor
		~Dog();

		//friend void debug_dog(const Dog& d);
		//friend struct ::point;

		void name(std::string name);
		const std::string& name() const;

		void breed(std::string breed);
		const std::string& breed() const;

		//void p(point p);
		//const point& p() const;

		void age(int age);
		const int& age() const;
		int* steal_age();

		static size_t m_count;
		inline static size_t m_count_inline {};

		/*Dog* setName(std::string_view name);
		std::string_view getName() const;

		Dog* setBreed(std::string_view breed);
		std::string_view getBreed() const;

		Dog* setAge(int age);
		int getAge() const;*/
	};
}
