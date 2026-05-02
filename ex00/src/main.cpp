#include "../includes/easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int	main()
{
	{
		std::cout << "=== TEST 1: Vector ===" << std::endl;
		std::cout << "Creating and populating a Vector of ints" << std::endl;
		std::vector<int> vec;

		vec.push_back(0);
		vec.push_back(42);
		vec.push_back(-23);

		// print the populated vector
		std::cout << "[ ";
		std::vector<int>::iterator it = vec.begin();
		while (it != vec.end())
		{
			// iterators behave like pointers, that's why we dereference to print the value of the element
			std::cout << *it << " ";
			++it;
		}
		std::cout << "]" << std::endl;

		std::cout << "Searching for 42..." << std::endl;
		try {
			std::vector<int>::iterator found = easyfind(vec, 42);
			std::cout << "Found: " << *found << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Searching for -1..." << std::endl;
		try {
			std::vector<int>::iterator found = easyfind(vec, -1);
			std::cout << "Found: " << *found << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "=== TEST 2: list ===" << std::endl;
		std::cout << "Creating and populating a list of ints" << std::endl;
		std::list<int> lis;

		lis.push_back(0);
		lis.push_back(42);
		lis.push_back(-23);

		// print the populated list
		std::cout << "[ ";
		std::list<int>::iterator it = lis.begin();
		while (it != lis.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << "]" << std::endl;

		std::cout << "Searching for 42..." << std::endl;
		try {
			std::list<int>::iterator found = easyfind(lis, 42);
			std::cout << "Found: " << *found << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Searching for -1..." << std::endl;
		try {
			std::list<int>::iterator found = easyfind(lis, -1);
			std::cout << "Found: " << *found << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "=== TEST 3: deque ===" << std::endl;
		std::cout << "Creating and populating a deque of ints" << std::endl;
		std::deque<int> deq;

		deq.push_back(0);
		deq.push_back(42);
		deq.push_back(-23);

		// print the populated deque
		std::cout << "[ ";
		std::deque<int>::iterator it = deq.begin();
		while (it != deq.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << "]" << std::endl;

		std::cout << "Searching for 42..." << std::endl;
		try {
			std::deque<int>::iterator found = easyfind(deq, 42);
			std::cout << "Found: " << *found << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Searching for -1..." << std::endl;
		try {
			std::deque<int>::iterator found = easyfind(deq, -1);
			std::cout << "Found: " << *found << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "=== TEST 4: edge cases ===" << std::endl;
		std::cout << "Testing empty container..." << std::endl;
		std::vector<int> empty;
		try {
			std::vector<int>::iterator found = easyfind(empty, -1);
			std::cout << "Found: " << *found << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Testing a const container..." << std::endl;
		int arr[] = {1, 3, -99, 42, 1};
		const std::list<int> lis(arr, arr + 5);
		std::cout << "[ ";
		std::list<int>::const_iterator it = lis.begin();
		while (it != lis.end())
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << "]" << std::endl;

		std::cout << "Searching for 42..." << std::endl;
		try {
			std::list<int>::const_iterator found = easyfind(lis, 42);
			std::cout << "Found: " << *found << std::endl;
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}
