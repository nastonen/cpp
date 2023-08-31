#include <iostream>

double add(double a, double b)
{
	return a + b;
}

double mult(double a, double b)
{
	return a * b;
}

// callbacks
char encrypt(const char& p)
{
	return static_cast<char>(p + 3);
}

char decrypt(const char& p)
{
	return static_cast<char>(p - 3);
}

// callback lambdas
auto encryptl = [](const char& p)
{
	return static_cast<char>(p + 3);
};

auto decryptl = [](const char& p)
{
	return static_cast<char>(p - 3);
};

using str_mod = char(*)(const char&);

void modify(std::string& str, str_mod mod)
{
	for (size_t i{}; i < str.size(); ++i)
		str[i] = mod(str[i]);
}

int main(void)
{
	double (*f_ptr) (double, double) = nullptr;
	
	if (1 == 0)
		f_ptr = add;
	else
		f_ptr = mult;

	std::cout << f_ptr(1, 2) << std::endl;

	std::string msg{ "Hello" };
	modify(msg, encryptl);
	modify(msg, decryptl);
	std::cout << msg << std::endl;
}
