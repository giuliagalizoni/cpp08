#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>

class Span
{
	private:
	unsigned int _N;
	std::vector<int> numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		// Public methods
		void addNumber(int number);

		template <typename Iterator>
  		void addNumber(Iterator begin, Iterator end)
		{
			if (numbers.size() + static_cast<unsigned int>(std::distance(begin, end)) > _N)
				throw Span::fullException();

			numbers.insert(numbers.end(), begin, end);
		}

		long longestSpan() const;
		long shortestSpan() const;

		class fullException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class emptyException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
