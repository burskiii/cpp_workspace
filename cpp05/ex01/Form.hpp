#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string name;
		bool Signed();
		const int gradeToSign();
		const int gradeToExec();

		void beSigned(Bureaucrat crat);
		
};

#endif
