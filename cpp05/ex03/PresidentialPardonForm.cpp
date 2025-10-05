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
    if (executor.getGrade() > getToExec())
        throw FormNotSignedException();
    if (!getIsSigned())
        throw FormNotSignedException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;

}