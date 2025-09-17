#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);
		Form f1("f1", 1, 1);
		Form f2("f2", 75, 75);
		Form f3("f3", 150, 150);

		std::cout << b1;
		std::cout << b2;
		std::cout << f1;
		std::cout << f2;
		std::cout << f3;

		b1.signForm(f1);
		b1.signForm(f2);
		b1.signForm(f3);

		b2.signForm(f1);
		b2.signForm(f2);
		b2.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
