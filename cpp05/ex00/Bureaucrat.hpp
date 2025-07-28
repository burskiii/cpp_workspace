#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat(&other));
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

	private:
		const std::string name;
		int grade;
} ;

#endif
