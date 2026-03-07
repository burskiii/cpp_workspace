#include "Span.hpp"

int main()
{
	span sp = span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(110);
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	std::cout << "---------------" << std::endl;	

	span sp2 = span(10000);
	std::vector<int> largeVector(10000);
	for (int i = 0; i < 10000; i++)
		largeVector[i] = i;
	sp2.addNumber(largeVector.begin(), largeVector.end(), 10000);
	std::cout << "Shortest Span in large vector: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest Span in large vector: " << sp2.longestSpan() << std::endl;

	return 0;
}
