#include "ShrubberyCreationForm.hpp"

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const 
{
    if (AForm::getToSign() == 145 && AForm::getToExec() == 137)
    {
        std::ofstream outfile(target + "_shrubbery");
        if (!outfile)
        {
            std::cerr << "Error creating file: " << target + "_shrubbery" << std::endl;
            return;
        }
        outfile << "       _-_\n"
                   "    /~~   ~~\\\n"
                   " /~~         ~~\\\n"
                   "{               }\n"
                   " \\  _-     -_  /\n"
                   "   ~  \\\\ //  ~\n"
                   "_- -   | | _- _\n"
                   "  _ -  | |   -_\n"
                   "      // \\\\\n";
        outfile.close();
    }
    else
    {
        throw GradeTooLowException();
    }
}