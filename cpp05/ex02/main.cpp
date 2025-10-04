#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat President("President", 5);
	Bureaucrat People("People", 145);
	Bureaucrat Minister("Minister", 72);

	std::cout << President << std::endl;
	std::cout << People << std::endl;
	std::cout << Minister << std::endl;

	std::cout << "--- Create Forms ---" << std::endl;
	ShrubberyCreationForm shrubbery("Garden");
	RobotomyRequestForm robot("Target");
	PresidentialPardonForm pardon("Criminal");

	std::cout << shrubbery << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	std::cout << "\n--- Try to sign with low-level bureaucrat ---\n";
	try {
		People.signForm(shrubbery);
		People.executeForm(shrubbery);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Sign and Execute Shrubbery with Minister ---\n";
	try {
		Minister.signForm(shrubbery);  // should work (grade 70 < sign
		Minister.executeForm(shrubbery);  // should work (exec requires 137)
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Sign and Execute Robotomy with President ---\n";
	try {
		President.signForm(robot);  // should work (grade 1 < sign 72)
		President.executeForm(robot);  // should work (exec requires 45)
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    std::cout << "\n--- Try to execute pardon before signing ---\n";
    try {
        President.executeForm(pardon);  // should throw FormNotSignedException
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Sign and Execute pardon with President ---\n";
    try {
        President.signForm(pardon);
        President.executeForm(pardon);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}
