#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string &getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

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

		void signForm();//must call Form::beSigned() to attempt to sign the form.
		//if the form is signed successfully, print:
			//<bureaucrat> signed <form>
		//otherwise
			//<bureaucrat> couldn’t sign <form> because <reason>.
	private:
		const std::string name;
		int grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat& b);

#endif
