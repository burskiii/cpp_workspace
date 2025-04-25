#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "Harl constructor called" << std::endl;
}

Harl::~Harl()
{
    std::cout << "Harl destructor called" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "Debug: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "Info: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for it!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "Warning: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "Error: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*func[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*func[i])();
            return ;
        }
    }
    std::cout << "Invalid level: " << level << std::endl;
}
