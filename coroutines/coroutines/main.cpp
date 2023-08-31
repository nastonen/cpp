#include <iostream>

coro[int] do_work()
{
	co_await std::suspend_always{};
	co_await std::suspend_always{};
}

coro[int] func2()
{
	int start{ 1 };

	while (true)
		co_yield start++;

	// co_return 55;
}

int main()
{
	auto f2 = func2();

	for (auto i{}; i < 10; ++i)
		std::cout << f2(); << std::endl;

	auto task = do_work();
	task.resume(); // runs and hits first suspenstion
	task.resume(); // runs and hits second suspenstion
	task.resume(); // runs and hits end of function
	// task.resume() // disaster.
}
