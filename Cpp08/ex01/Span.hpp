#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <climits>
# include <cstddef>
# include <iostream>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

		Span();

	public:
		explicit Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		void addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
	};

#endif