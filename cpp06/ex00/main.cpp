#include <iostream>
#include <string>
#include <sstream>
#include "ScarlaConverter.hpp"


int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
        return 1;
    }

    ScarlaConverter::convert(argv[1]);
    return 0;


}