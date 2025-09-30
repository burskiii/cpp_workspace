#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), toSign(150), toExec(150) {
    if (toSign < 1 || toExec < 1)
        throw GradeTooHighException();
    if (toSign > 150 || toExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string &name, int toSign, int toExec)
    : name(name), isSigned(false), toSign(toSign), toExec(toExec) {
    if (toSign < 1 || toExec < 1)
        throw GradeTooHighException();
    if (toSign > 150 || toExec > 150)
        throw GradeTooLowException();
}
AForm::~AForm(){}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned; 
        //tips: cant add value to const members;
    }
    return *this;
}

const std::string &AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getToSign() const
{
    return this->toSign;
}

int AForm::getToExec() const
{
    return this->toExec;
}

void AForm::Signed(const Bureaucrat &b)
{
    if (b.getGrade() > this->toSign)
        throw GradeTooLowException();
    else
        this->isSigned = true;
}
std::ostream &operator<<(std::ostream &out, const AForm &f)
{
    out << "Form " << f.getName() << ", sign status: " << (f.getIsSigned() ? "signed" : "not signed")
        << ", grade required to sign: " << f.getToSign()
        << ", grade required to execute: " << f.getToExec() << ".";
    return out;
}



