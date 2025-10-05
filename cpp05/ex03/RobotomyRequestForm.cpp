#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
    if (executor.getGrade() > getToExec())
        throw AForm::GradeTooLowException();
    if (!getIsSigned())
        throw AForm::GradeTooLowException();

    std::cout << "Brrrr... Brrrr... Drilling noises..." << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy failed on " << target << "." << std::endl;
}

