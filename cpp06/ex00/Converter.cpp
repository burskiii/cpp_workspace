#include "Converter.hpp"


// forward declarations (ensures the helper functions are visible to member definitions)
bool isWithPoint(const std::string& input);
bool isNotDigit(const std::string& input);


Converter::Converter() {

    isFloat = false;
}

void Converter::convertToChar(const std::string& input)
{
    // char c;
    int len = input.size();

    if ((input >= "0" && input <= "9") && len == 1)
        std::cout << "char: Non displayable" << std::endl;
    else if (isWithPoint(input) == true)
        std::cout << "char: '*'" << std::endl;
    else if (((input >= "A" && input <= "Z") || (input >= "a" && input <= "z")) && len > 1)
        std::cout << "char: impossible" << std::endl;

}

void Converter::convertToInt(const std::string& input)
{
    int number;
    std::stringstream converter;

    if ((isNotDigit(input)) == true)
    {
        std::cout << "Int: impossible" << std::endl;
    }
    else if (hasSignOrPoint(input) && isNotDigit(input) == false)
    {
        number = floatToInt(input);
        std::cout << "Int: " << number << std::endl;
    }
    else
    {
        converter << input;
        converter >> number;
        std::cout << "Int: " << number << std::endl;
    }
}

void Converter::converToDouble(const std::string& input)
{
    // to be implemented
}

bool Converter::isWithPoint(const std::string& input)
{
    for (int i = 0; input[i]; i++)
    {
        if (input[i] == '.')
            return true;
    }
    return false;
}

bool Converter::isNotDigit(const std::string& input)
{
    int len = input.size();

    for (int i = 0; input[i]; i++)
    {
        if (input[0] == '-' || input[0] == '+')
            continue;
        else if ((input[i] < '0' || input[i] > '9') && input[i] != '.' && input[len - 1] != 'f')
        {
            //std::cout << "Debug: found non-digit character: " << input[i] << std::endl;
            return true;
        }
        else if (input[i] == '.')
            continue;
    }
    return false;
}

bool Converter::hasSignOrPoint(const std::string& input)
{
    for (int i = 0; input[i]; i++)
    {
        if (input[i] == '.' || input[i] == '-' || input[i] == '+')
            return true;
    }
    return false;
}

int Converter::floatToInt(const std::string& input)
{
    int number = 0;
    for (int i = 0; input[i]; i++)
    {
        if (input[i] == '-')
            number = -number;
        else if (input[i] >= '0' && input[i] <= '9')
            number = number * 10 + (input[i] - '0');
        else if (input[i] == '.')
        {
            isFloat = true;
            break;
        }
        else if ((input[(input.size()) - 1] == 'f') && hasSignOrPoint(input))
        {
            isFloat = true;
            break;
        }
    }
    return number;
}