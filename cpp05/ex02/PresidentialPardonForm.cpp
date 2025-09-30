#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"


#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const 
{
    if (AForm::getToSign() == 25 && AForm::getToExec() == 5)
    {
        std::cout << "Presidential Pardon granted to " << target << std::endl;
    }
    else
    {
        throw GradeTooLowException();
    }
}