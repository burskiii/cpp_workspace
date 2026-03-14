#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}


void RPN::calculate(const std::string &argv) {

    int i = 0;
    std::stack<int> &stack = this->_stack;
    
    while (argv[i])
    {
        if (argv[i] == ' ')
        {
            i++;
            continue;
        }
        if (isdigit(argv[i]) && argv[i] >= '0' && argv[i] <= '9')
        {
            stack.push(argv[i] - '0');
            i++;
        }
        if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            else if (argv[i] == '+')
            {
                int a = stack.top();//check the top number of stack
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b + a);
            }
            else if (argv[i] == '-')
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b - a);
            }
            else if (argv[i] == '*')
            {
                int a = stack.top();//check the top number of stack
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b * a);
            }
            else if (argv[i] == '/')
            {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b / a);
            }
            else
            {
                std::cerr << "Error: invalid character " << argv[i] << std::endl;
                return;
            }
        }
        i++;
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::cout << stack.top() << std::endl;
    stack.pop();
}