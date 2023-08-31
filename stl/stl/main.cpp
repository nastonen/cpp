#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <deque>
#include <algorithm>
#include <forward_list>
#include <utility>
#include <set>
#include <map>
#include <cassert>
#include <stack>
#include <queue>
#include <list>

template <typename T>
void print_vec(const std::vector<T>& vec)
{
	for (size_t i{}; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

template <typename T, size_t Size>
void print_arr(const std::array<T, Size>& arr)
{
	for (size_t i{}; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void print_collection(const T& c)
{
	// use std::cbegin() and std::cend() for raw arrays
	auto it = c.cbegin();

	std::cout << "[";
	while (it != c.cend())
		std::cout << " " << *it++;
	std::cout << " ]" << std::endl;
}

template <typename T>
void print_collection_reverse(const T& c)
{
	auto it = c.crbegin();

	std::cout << "[";
	while (it != c.crend())
		std::cout << " " << *it++;
	std::cout << " ]" << std::endl;
}

template <typename T, typename K>
void print_map(const std::map<T, K>& map)
{
	auto it = map.begin();

	std::cout << "map of elements: [";
	while (it != map.end()) {
		std::cout << " [" << it->first << ":" << it->second << "]";
		++it;
	}
	std::cout << " ]" << std::endl;
}

template <typename T, typename Container = std::deque<T>>
void print_stack(std::stack<T, Container> stack)
{
	// we are working on a copy here. IMPORTANT

	std::cout << "stack of elements [";
	while (!stack.empty()) {
		std::cout << " " << stack.top();
		stack.pop();
	}
	std::cout << " ]" << std::endl;
}

template<typename T, typename Container = std::deque<T>>
void print_queue(std::queue<T, Container> queue)
{
	// we are working on a copy here. IMPORTANT

	std::cout << "queue of items [";
	while (!queue.empty()) {
		std::cout << " " << queue.front();
		queue.pop();
	}
	std::cout << " ]" << std::endl;
}

template<typename T,
		 typename Container = std::vector<T>,
		 typename Compare = std::greater<typename Container::value_type>>
void print_priority_queue(std::priority_queue<T, Container, Compare> queue)
{
	// we are working on a copy here. IMPORTANT

	std::cout << "queue of items [";
	while (!queue.empty()) {
		std::cout << " " << queue.top();
		queue.pop();
	}
	std::cout << " ]" << std::endl;
}

template<typename T>
inline void my_remove(std::vector<T>& v, const T& item)
{
	// Be careful: if you omit the v.end() parameter to v.erase, the
	// code will compile but only a single item will be removed.
	v.erase(std::remove(v.begin(), v.end(), item), v.end());
}

int main(void)
{
	// vector
	std::vector<int> ints1;
	ints1.reserve(10);
	ints1.push_back(1);
	ints1.push_back(3);
	ints1.push_back(1);
	print_vec(ints1);

	// remove all occurences of 1
	my_remove(ints1, 1);
	print_vec(ints1);

	std::vector<std::string> vec_str{ "is", "The", "sky", "is", "blue", "my", "friend", "is" };
	// remove all occurences of 'is'
	std::string r = "is";
	my_remove(vec_str, r);

	print_collection_reverse(vec_str);

	// array
	std::array<int, 3> arr1;
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	std::sort(arr1.rbegin(), arr1.rend());
	print_collection_reverse(arr1);

	// .at() does bound checking and can be caught!
	try {
		int i = arr1.at(50);
	}
	catch (std::out_of_range&) {
		std::cout << "arr1 out of range..." << std::endl;
	}

	// deque
	std::deque<int> nums = { 1,2,3,4,5 };
	nums.push_front(100);
	std::sort(nums.begin(), nums.end());
	print_collection(nums);

	// forward list (singly linked list)
	std::forward_list<int> fl{ 1,2,3,1,2,3,100,-1,100,1 };
	// remove all occurences
	fl.remove_if([](int n) {return n == 1;});
	print_collection(fl);

	// pair
	std::pair<int, std::string> p1{ 0, "Book" };
	auto p2 = std::make_pair(1, "Table");
	std::cout << "pair1: (" << p1.first << ", " << p1.second << ")" << std::endl;
	std::cout << "pair2: (" << p2.first << ", " << p2.second << ")" << std::endl;

	std::vector<std::pair<int, std::string>> vp = { {1, "one"}, {2, "two"}, {3, "three"} };
	for (const auto& p : vp)
		std::cout << "(" << p.first << ":" << p.second << ") ";
	std::cout << std::endl;

	// set
	std::set<int, std::greater<int>> numset{ 11, 16, 2, 912, 15, 15, 2 };
	print_collection(numset);

	// map
	std::map<int, int> m{ {1,11}, {2,22}, {3,33}, {4,44} };

	const auto& res = m.insert_or_assign(1, std::move(22));
	assert(res.second == false);

	const auto& res1 = m.try_emplace(1, 22);
	if (!res1.second)
		std::cout << "1 already exists\n";

	std::cout << "was 5 emplaced? " << m.try_emplace(5, 55).second << std::endl;
	std::cout << "was 5 erased? " << m.erase(5) << std::endl;
	//int i = map.contains(9) ? map.at(9) : 0; // c++20
	auto i = (m.find(4) == m.end()) ? 0 : m.at(4);
	//std::cout << i << std::endl;
	
	//print_map(map);
	for (const auto& [key, val] : m)
		std::cout << key << ":" << val << " ";
	std::cout << std::endl;


	// stack
	//std::stack<int, std::vector<int>> s;	// underlying container: vector
	//std::stack<int, std::list<int>> s;		// underlying container: list
	//std::stack<int, std::deque<int>> s;	// underlying container: deque

	/*
	* auto& tmp = top(); // returns a reference
	* auto tmp = top(); // returns a COPY!
	*/

	std::stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.top() = 55;
	print_stack(s);

	// queue
	std::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.back() = 55;
	print_queue(q);

	// priority queue
	std::priority_queue<int, std::deque<int>, std::greater<int>> pq; // std::less<int> is default
	pq.push(10);
	pq.push(8);
	pq.push(12);
	//pq.top() = 55; // error! top() returns const
	std::cout << pq.top() << std::endl;
	//pq.pop();
	print_priority_queue(pq);
}
