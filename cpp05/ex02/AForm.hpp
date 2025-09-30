#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <sstream>

class Bureaucrat;

class AForm {
    private:
        bool isSigned;
        const std::string name;
        int toSign;
        int toExec;

    public:
        AForm();
        AForm(const AForm &other);
        AForm(const std::string &name, int toSign, int toExec);
        AForm &operator=(const AForm &other);
        ~AForm();

        const std::string &getName() const;
        bool getIsSigned() const;
        int getToSign() const;
        int getToExec() const;
        void Signed(const Bureaucrat &b);

        
        class GradeTooHighException : public std::exception {
            public: 
                const char *what() const noexcept {
                    return "Grade is too high.";
                }        
        };
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const noexcept {
                    return "Grade is too low.";
                }
        };
        friend std::ostream &operator<<(std::ostream &out, const AForm &f);

};

#endif