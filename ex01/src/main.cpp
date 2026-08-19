#include "../includes/Span.hpp"
#include <iostream>
#include <list>
#include <cstdlib>

int main()
{
	std::cout << ">>>>> TEST 1: single addNumber <<<<<" << std::endl;
	Span span(4);
	span.addNumber(1);
	span.addNumber(-2);
	span.addNumber(20);
	span.addNumber(5);
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;

	std::cout << std::endl << ">>>>> TEST 2: range insert from vector <<<<<" << std::endl;
	std::vector<int> src;
	src.push_back(3);
	src.push_back(7);
	src.push_back(1);
	src.push_back(9);
	src.push_back(2);
	Span s2(10);
	s2.addNumber(src.begin(), src.end());
	std::cout << "Longest span: " << s2.longestSpan() << std::endl;
	std::cout << "Shortest span: " << s2.shortestSpan() << std::endl;

	std::cout << std::endl << ">>>>> TEST 3: range insert into partially filled Span <<<<<" << std::endl;
	Span s3(10);
	s3.addNumber(42);
	s3.addNumber(src.begin(), src.end());
	std::cout << "Longest span: " << s3.longestSpan() << std::endl;
	std::cout << "Shortest span: " << s3.shortestSpan() << std::endl;

	std::cout << std::endl << ">>>>> TEST 4: range fills exactly remaining capacity <<<<<" << std::endl;
	Span s4(5);
	s4.addNumber(src.begin(), src.end());
	std::cout << "Longest span: " << s4.longestSpan() << std::endl;
	std::cout << "Shortest span: " << s4.shortestSpan() << std::endl;

	std::cout << std::endl << ">>>>> TEST 5: empty range insert (should do nothing) <<<<<" << std::endl;
	std::vector<int> empty;
	Span s5(5);
	s5.addNumber(empty.begin(), empty.end());
	std::cout << "Numbers added: 0 (no throw expected)" << std::endl;

	std::cout << std::endl << ">>>>> TEST 6: range from std::list (template genericity) <<<<<" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	Span s6(5);
	s6.addNumber(lst.begin(), lst.end());
	std::cout << "Longest span: " << s6.longestSpan() << std::endl;
	std::cout << "Shortest span: " << s6.shortestSpan() << std::endl;

	std::cout << std::endl << ">>>>> TEST 7: range exceeds total capacity (should throw) <<<<<" << std::endl;
	try {
		Span s7(3);
		s7.addNumber(src.begin(), src.end());
		std::cout << "ERROR: should have thrown" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << ">>>>> TEST 8: range exceeds remaining capacity (should throw, no partial insert) <<<<<" << std::endl;
	try {
		Span s8(5);
		s8.addNumber(1);
		s8.addNumber(2);
		s8.addNumber(src.begin(), src.end());
		std::cout << "ERROR: should have thrown" << std::endl;
	} catch (std::exception& e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << ">>>>> TEST 9: 10000 numbers <<<<<" << std::endl;
	{
		std::vector<int> big;
		for (int i = 0; i < 10000; i++)
			big.push_back(rand());

		Span s9(10000);
		s9.addNumber(big.begin(), big.end());

		std::cout << "Longest span: " << s9.longestSpan() << std::endl;
		std::cout << "Shortest span: " << s9.shortestSpan() << std::endl;
	}

	std::cout << std::endl << ">>>>> TEST 10: 1000000 numbers <<<<<" << std::endl;
	{
		std::vector<int> huge;
		for (int i = 0; i < 1000000; i++)
			huge.push_back(rand());

		Span s10(1000000);
		s10.addNumber(huge.begin(), huge.end());

		std::cout << "Longest span: " << s10.longestSpan() << std::endl;
		std::cout << "Shortest span: " << s10.shortestSpan() << std::endl;
	}

	return 0;
}
