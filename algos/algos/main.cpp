#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>
#include <utility>

struct Point
{
	int x;
	int y;
};

int main(void)
{
	/*
		* DEPRECATED
	*/

	// all_of, any_of, none_of
	std::vector<int> arr { 2, 6, 8, 40, 64, 70, 7 };

	if (std::all_of(std::begin(arr), std::end(arr), [](int i) {return i % 2 == 0;}))
		std::cout << "(std::all_of): All number in collection are even." << std::endl;
	else
		std::cout << "(std::all_of): Not all number in collection are even." << std::endl;

	// for_each
	std::for_each(std::begin(arr), std::end(arr), [](int& n) {++n;});
	std::for_each(std::begin(arr), std::end(arr), [](const int& n) {std::cout << " " << n;});
	std::cout << std::endl;

	// min_element, max_element
	const auto& [min, max] = std::minmax_element(std::begin(arr), std::end(arr));
	std::cout << "min: " << *min << ", max: " << *max << std::endl;

	// find & find_if
	int n = 55;
	auto res = std::find(std::begin(arr), std::end(arr), n);
	if (res == std::end(arr))
		std::cout << "not ";
	std::cout << "found " << n << std::endl;

	// sort
	std::sort(std::begin(arr), std::end(arr));
	std::for_each(std::begin(arr), std::end(arr), [](const int& n) {std::cout << " " << n;});
	std::cout << std::endl;

	std::cout << "-------------------------------" << std::endl;


	/*
		* C++20
	*/

	// all_of, any_of, none_of
	if (std::ranges::all_of(arr, [](int i) {return i % 2 == 0;}))
		std::cout << "(std::all_of): All number in collection are even." << std::endl;
	else
		std::cout << "(std::all_of): Not all number in collection are even." << std::endl;

	// for_each
	std::ranges::for_each(arr, [](int& n) {++n;});
	std::ranges::for_each(arr, [](const int& n) {std::cout << " " << n;});
	std::cout << std::endl;

	// min_element, max_element
	const auto& [min1, max1] = std::ranges::minmax_element(arr);
	std::cout << "min: " << *min1 << ", max: " << *max1 << std::endl;

	// find & find_if
	int n1 = 55;
	auto res1 = std::ranges::find(arr, n1);
	if (res1 == std::end(arr))
		std::cout << "not ";
	std::cout << "found " << n << std::endl;

	// sort
	std::ranges::sort(arr);
	std::ranges::for_each(arr, [](const int& n) {std::cout << " " << n;});
	std::cout << std::endl;

	// projections
	std::vector<Point> pv{ {30,30}, {10,10}, {20,20} };
	// sort based on 'x' member variable using projection
	std::ranges::sort(pv, std::less<>{}, &Point::x);
	std::ranges::for_each(pv, [](const Point& p) {std::cout << " " << p.x;});


	/*
	 *  Views
	 */

	// takes elements as long as the predicate condition is met
	std::ranges::take_while_view v = std::ranges::take_while_view(arr, [](int i) {return (i % 2 != 0);});
	std::ranges::for_each(v, [](const int i) {std::cout << " " << i;});
	std::cout << std::endl;

	// get only keys or values from a collection (hashmap also?) in a view
	std::vector<std::pair<int, std::string>> nums { {1, "one"}, {2, "two"}, {3, "three"} };
	auto ks = std::views::keys(nums);
	auto vs = std::views::values(nums);

	std::cout << "keys: ";
	std::ranges::for_each(ks, [](const auto& k) {std::cout << " " << k;});
	std::cout << std::endl;

	std::cout << "values: ";
	std::ranges::for_each(vs, [](const auto& v) {std::cout << " " << v;});
	std::cout << std::endl;

	// filter view, collect only even numbers
	auto fv = std::ranges::filter_view(arr, [](int i) {return !(i & 1);});

	// drop_while removes elements

	
	// view compositions !!IMPORTANT!!
	arr = { 7, 3, 12, 6, 5, 20, 4, 90 };

	std::cout << "arr before view composition: ";
	std::ranges::for_each(arr, [](const auto& v) {std::cout << v << " ";});
	std::cout << std::endl;

	// take only even numbers and square them
	// not modifying input data, because passing by value
	auto even = [](int n) {return !(n & 1);};
	auto square = [](int n) {return n *= n;};
	auto my_view = arr
		| std::views::filter(even)
		| std::views::transform(square);

	std::cout << "arr after view composition: ";
	std::ranges::for_each(my_view, [](const auto& v) {std::cout << v << " ";});
	std::cout << std::endl;
}
