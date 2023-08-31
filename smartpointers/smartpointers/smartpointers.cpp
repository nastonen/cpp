#include <iostream>
#include <memory>
#include "dog.h"

void take_ownership(std::unique_ptr<dog> dog)
{
	std::cout << "Ownership of " << dog->dog_name << " taken" << std::endl;
}

void by_ref(/*const*/ std::unique_ptr<dog>& dog)
{
	dog->dog_name = "changed";
	std::cout << "Reference of " << dog->dog_name << " taken" << std::endl;
}

void implicit_move(std::unique_ptr<dog> dog)
{
	std::cout << "Implicit std::move of " << dog->dog_name << " pointer made" << std::endl;
}

// RVO, no copy is made
std::unique_ptr<dog> dog_factory()
{
	return std::make_unique<dog>("Dog from the factory");
}

// RVO, no copy is made
std::shared_ptr<dog> shared_dog_factory()
{
	return std::make_shared<dog>("Shared dog from factory");
}

int main()
{
	/*
	* Unique pointers
	*/
	
	/*dog dog1("Dog1");
	dog1.print_dog();

	dog* p_dog2 = new dog("Dog2");
	std::unique_ptr<dog> up_dog3 {p_dog2};
	up_dog3->print_dog();*/

	//std::unique_ptr<dog> up_dog4 = std::make_unique<dog>("Dog4");
	//up_dog4->print_dog();

	//std::unique_ptr<dog> up_dog5 = std::move(up_dog4);
	//up_dog5->print_dog();

	//if (!up_dog4)
		//std::cout << "up_dog4 is nullptr" << std::endl;

	//std::cout << "before func" << std::endl;
	//take_ownership(std::move(up_dog5));
	//by_ref(up_dog4);
	//implicit_move(std::make_unique<dog>("Tmp dog"));
	//dog_factory()->print_dog();
	//std::cout << "after func" << std::endl;

	//auto arr_ptr = std::make_unique<dog[]>(3);
	//auto arr_ptr1 = std::unique_ptr<dog[]>(new dog[3]{ dog("One"), dog("Two"), dog("Three") });


	/*
	* Shared pointers
	*/

	std::shared_ptr<dog> sd1 = std::make_shared<dog>("Shared dog 1");
	std::shared_ptr<dog> sd2 {sd1};

	std::cout << sd1.use_count() << std::endl;
	sd1.reset();
	std::cout << sd1.use_count() << std::endl;
	//sd2.get()->print_dog();
	sd2.reset();
	std::cout << "after reset" << std::endl;

	std::shared_ptr<dog> sd3 = dog_factory();
	std::shared_ptr<dog> sd4 {sd3};
	std::cout << sd3.use_count() << std::endl;

	std::unique_ptr<dog> up_dog6 = std::make_unique<dog>("dog 6");
	std::shared_ptr<dog> sd5 = std::move(up_dog6);

	std::shared_ptr<dog> sdf = shared_dog_factory();
	std::cout << sdf.use_count() << std::endl;

	//std::weak_ptr<dog> d = sdf;
	//d.expired(); // check if weak_ptr is a dangling pointer
}
