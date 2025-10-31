#include <iostream>
#include <string>
#include <sstream>
#include "Converter.hpp"


int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
        return 1;
    }
    std::string input = argv[1];
   Converter converter;

   converter.convertToChar(input);
   converter.convertToInt(input);


}