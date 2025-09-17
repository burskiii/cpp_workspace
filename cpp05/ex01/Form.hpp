#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
	private:
		std::string name;
		bool Signed;
		int gradeToSign;
		int gradeToExec;
		
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form &operator=(const Form &other);
		~Form();
		
		const std::string &getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(const Bureaucrat &crat);
		std::string getReason() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too high!");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too low!");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Form& f);

#endif
