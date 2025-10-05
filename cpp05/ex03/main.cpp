#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	// Bureaucrat President("President", 5);
	// Bureaucrat People("People", 145);
	// Bureaucrat Minister("Minister", 72);

	// std::cout << President << std::endl;
	// std::cout << People << std::endl;
	// std::cout << Minister << std::endl;

	// std::cout << "--- Create Forms ---" << std::endl;
	// ShrubberyCreationForm shrubbery("Garden");
	// RobotomyRequestForm robot("Target");
	// PresidentialPardonForm pardon("Criminal");

	// std::cout << shrubbery << std::endl;
	// std::cout << robot << std::endl;
	// std::cout << pardon << std::endl;

	// std::cout << "\n--- Try to sign with low-level bureaucrat ---\n";
	// try {
	// 	People.signForm(shrubbery);
	// 	People.executeForm(shrubbery);
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// std::cout << "\n--- Sign and Execute Shrubbery with Minister ---\n";
	// try {
	// 	Minister.signForm(shrubbery);  // should work (grade 70 < sign
	// 	Minister.executeForm(shrubbery);  // should work (exec requires 137)
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// std::cout << "\n--- Sign and Execute Robotomy with President ---\n";
	// try {
	// 	President.signForm(robot);  // should work (grade 1 < sign 72)
	// 	President.executeForm(robot);  // should work (exec requires 45)
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

    // std::cout << "\n--- Try to execute pardon before signing ---\n";
    // try {
    //     President.executeForm(pardon);  // should throw FormNotSignedException
    // } catch (const std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // std::cout << "\n--- Sign and Execute pardon with President ---\n";
    // try {
    //     President.signForm(pardon);
    //     President.executeForm(pardon);
    // } catch (const std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }

	// std::cout << "\n--- Test Intern creates forms ---" << std::endl;

	Intern someIntern;

	try {
		AForm *f1 = someIntern.makeForm("shrubbery creation", "Home");
		std::cout << *f1 << std::endl;
		delete f1;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		AForm *f2 = someIntern.makeForm("robotomy request", "Wall-E");
		std::cout << *f2 << std::endl;
		delete f2;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		AForm *f3 = someIntern.makeForm("presidential pardon", "Rick");
		std::cout << *f3 << std::endl;
		delete f3;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		AForm *bad = someIntern.makeForm("undefined form", "Ghost");
		delete bad;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
