#include "Span.hpp"

span::span():n(0), vector(std::vector<int>())
{

}

span::span(span const &other)
{
    n = other.n;
    vector = other.vector;
}

span::span(unsigned int n):n(n), vector(std::vector<int>())
{

}

span &span::operator=(span const &other)
{
    if(this != &other)
    {
        n = other.n;
        vector = other.vector;
    }
    return *this;
}

span::~span()
{

}

void span::addNumber(unsigned int n)
{
	if (vector.size() >= n)
		throw spanIsFull();
	vector.push_back(n);
}

void span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end, unsigned int n)
{
	if (std::distance(begin, end) + vector.size() > n)
		throw spanIsFull();
	vector.insert(vector.end(), begin, end);
}

int span::shortestSpan()
{
	if (vector.size() < 2)
		throw spanNumLacking();
	std::vector<int> sorted(vector);
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] - sorted[0];
	for (unsigned int i = 2; i < sorted.size(); i++)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int span::longestSpan()
{
	if (vector.size() < 2)
		throw spanNumLacking();
	int min = *std::min_element(vector.begin(), vector.end()); // available in C++98, returns an iterator to the minimum element in the range [first, last)
	int max = *std::max_element(vector.begin(), vector.end()); // available in C++98, returns an iterator to the maximum element in the range [first, last)
	return max - min;
}

const char *span::spanIsFull::what() const throw()
{
	return "Span is full";
}

const char *span::spanNumLacking::what() const throw()
{
	return "Not enough numbers to find a span";
}
