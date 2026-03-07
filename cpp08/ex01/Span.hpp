#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class span {
	
	
	public:
		span();
		span(unsigned int i);
		span(span const &other);
		span &operator=(span const &other);
		~span();

		void addNumber(unsigned int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end, unsigned int n);
		int shortestSpan();
		int longestSpan();

		class spanIsFull: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class spanNumLacking: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	
	private:
		unsigned int n;
		std::vector<int> vector;
};

#endif
