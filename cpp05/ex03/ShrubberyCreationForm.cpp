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
    if (executor.getGrade() > getToExec())
        throw AForm::GradeTooLowException();
    if (!getIsSigned())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "Error: Could not open file " << target + "_shrubbery" << std::endl;
        return;
    }

    outfile << "    🌳🌲 ASCII TREE 🌲🌳\n";
    outfile << "       _-_" << std::endl;
    outfile << "    /~~    ~~\\" << std::endl;
    outfile << "  /~~      ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;
    outfile.close();
}
