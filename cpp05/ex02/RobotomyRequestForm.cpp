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
    if (AForm::getToSign() == 72 && AForm::getToExec() == 45)
    {
        std::cout << "Brrrr... Brrrr... Drilling noises..." << std::endl;
        std::srand(std::time(nullptr));
        if (std::rand() % 2)
            std::cout << target << " has been robotomized successfully." << std::endl;
        else
            std::cout << "Robotomy failed on " << target << "." << std::endl;
    }
    else
    {
        throw GradeTooLowException();
    }
}

