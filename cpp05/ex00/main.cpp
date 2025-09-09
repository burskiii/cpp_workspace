#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("A", 1);
	std::cout << a <<std::endl;

	Bureaucrat b("B", 150);
	std::cout << b <<std::endl;

	std::cout << "Bureaucrat c('C', 0);" << std::endl;
	try
	{
		Bureaucrat c("C", 0);
		std::cout << c <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << "Bureaucrat d('D', 151);" << std::endl;
	try
	{
		Bureaucrat d("D", 151);
		std::cout << d <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << "increment_test from a" << std::endl;
	try
	{
		a.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << "decrement_test from b" << std::endl;
	try
	{
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	return 0;

}
