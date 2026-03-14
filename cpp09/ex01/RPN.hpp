#ifndef RPN_HPP
#define RPN_HPP


#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>


class RPN {
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void calculate(const std::string& argv);

    private:
        std::stack<int> _stack;

};
#endif
