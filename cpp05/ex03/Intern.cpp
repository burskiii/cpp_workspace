#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm *createShrubbery(std::string const &target);
AForm *createRobotomy(std::string const &target);
AForm *createPardon(std::string const &target);


AForm *createShrubbery(std::string const &target) {
    return new ShrubberyCreationForm(target);
}

AForm *createRobotomy(std::string const &target) {
    return new RobotomyRequestForm(target);
}

AForm *createPardon(std::string const &target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) 
{
    FormType forms[3];

    forms[0].name = "shrubbery creation";
    forms[0].createFunc = &createShrubbery;

    forms[1].name = "robotomy request";
    forms[1].createFunc = &createRobotomy;

    forms[2].name = "presidential pardon";
    forms[2].createFunc = &createPardon;

    for (int i = 0; i < 3; i++) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].createFunc(target);
        }
    }
    std::cout << "Intern: form \"" << formName << "\" not found" << std::endl;
    return NULL;
}
