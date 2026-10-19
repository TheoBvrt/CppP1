#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N)
{
	_numbers.reserve(N);
}

Span::Span(const Span& other)
	: _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::overflow_error("Span is full");

	_numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::const_iterator begin,
	std::vector<int>::const_iterator end)
{
	std::size_t count = static_cast<std::size_t>(end - begin);

	if (count > _maxSize - _numbers.size())
		throw std::overflow_error("Not enough space in Span");

	_numbers.insert(_numbers.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = UINT_MAX;

	for (std::size_t i = 1; i < sorted.size(); ++i)
	{
		long long diff = (long long)sorted[i] - (long long)sorted[i - 1];
		unsigned int distance = (unsigned int)diff;
		if (distance < shortest)
			shortest = distance;
	}

	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	int minValue = *std::min_element(_numbers.begin(), _numbers.end());
	int maxValue = *std::max_element(_numbers.begin(), _numbers.end());

	return static_cast<unsigned int>(
		static_cast<long long>(maxValue) - static_cast<long long>(minValue)
	);
}
