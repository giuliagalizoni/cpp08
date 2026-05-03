#include "../includes/Span.hpp"

// Default constructor
Span::Span() : _N(0) {}

Span::Span(unsigned int N): _N(N) {}

// Copy constructor
Span::Span(const Span& other)
{
	*this = other;
}

// Copy assignment operator
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_N = other._N;
		numbers = other.numbers;
	}
	return *this;
}

// Destructor
Span::~Span() {}

// Public methods implementation
void Span::addNumber(int number)
{
	if (numbers.size() == _N)
		throw Span::fullException();

	numbers.push_back(number);
}

long Span::longestSpan() const
{
	if (numbers.empty() || numbers.size() == 1)
		throw Span::emptyException();

	return static_cast<long>(*std::max_element(numbers.begin(), numbers.end())) - *std::min_element(numbers.begin(), numbers.end());
}

long Span::shortestSpan() const
{
	if (numbers.empty() || numbers.size() == 1)
		throw Span::emptyException();

	std::vector<int> copy = numbers;
	std::sort(copy.begin(), copy.end());

	long min = static_cast<long>(copy[1]) - copy[0];
	for (std::vector<int>::iterator it = copy.begin() + 1; it + 1 != copy.end(); ++it)
	{
		if (static_cast<long>((*(it + 1))) - *it < min)
			min = static_cast<long>(*(it + 1)) - *it;
	}

	return min;
}

const char *Span::fullException::what() const throw()
{
	return "There is no more space; container is full.";
}

const char *Span::emptyException::what() const throw()
{
	return "Span not possible; container is empty or has only one number";
}
