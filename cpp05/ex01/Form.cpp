#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() {}

Form::Form(const std::string name, int gradeToSign, int gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	this->name = name;
	this->Signed = false;
	this->gradeToSign = gradeToSign;
	this->gradeToExec = gradeToExec;
}

Form::Form(const Form& other) {
	*this = other;
}
Form &Form::operator=(const Form &other) {
	if (this != &other)
	{
		this->Signed = other.Signed;
		this->gradeToSign = other.gradeToSign;
		this->gradeToExec = other.gradeToExec;
	}
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
	return this->name;
}

bool Form::getSigned() const {
	return this->Signed;
}

int Form::getGradeToSign() const {
	return this->gradeToSign;
}

std::string Form::getReason() const {
	if (this->Signed == true)
		return "the form is already signed.";
	else
		return "the bureaucrat's grade is too low.";
}

int Form::getGradeToExec() const {
	return this->gradeToExec;
}

void Form::beSigned(const Bureaucrat& crat) {
    if (crat.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->Signed = true;

}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << "Form " << f.getName()
        << ", form grade to sign " << f.getGradeToSign()
        << ", form grade to execute " << f.getGradeToExec()
        << ", form signed status " << (f.getSigned() ? "true" : "false") << "." << std::endl;
    return out;
}
