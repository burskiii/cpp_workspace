#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio> //required for sprintf
#include <sstream> //required for std::stringsream

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "The Memory address of the string variable: " << &string << std::endl;
    std::cout << "The Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The Memory address held by stringREF: " << &stringREF << std::endl;

    std::cout << "The value of the string variable: " << string <<std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
    return (0);
}
