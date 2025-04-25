#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    std::string level;

    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }
    else 
    {
        level = argv[1];
        if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
        {
            std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
            return 1;
        }
        else
            harl.complain(level);
    }
    return 0;
}
