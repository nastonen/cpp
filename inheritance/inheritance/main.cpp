#include <iostream>
#include "Footballer.h"

int main()
{
	Footballer f1("Niko", 35, "Vihto", 100000, 50);
	std::cout << f1 << std::endl;
	
	Footballer f2(f1);
	std::cout << f2 << std::endl;
}
