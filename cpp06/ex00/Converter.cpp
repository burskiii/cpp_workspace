#include "Converter.hpp"

Converter::Converter() {}

Converter::~Converter() {}

bool Converter::isPseudoLiteral(const std::string& input)
{
    return (input == "nan" || input == "+inf" || 
            input == "-inf" || input == "nanf" || 
            input == "+inff" || input == "-inff");
}

void Converter::convertToChar(const std::string& input)
{
    if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
    {
        std::cout << "char: '" << input[0] << "'" << std::endl;
        return;
    }

    if (isPseudoLiteral(input) || isNotDigit(input))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    // convert to int and check range (ASCII 0-127)
    int value = std::atoi(input.c_str());
    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(value))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void Converter::convertToInt(const std::string& input)
{
    if (isPseudoLiteral(input) || isNotDigit(input))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    int number = 0;
    std::stringstream converter(input);
    converter >> number;
    std::cout << "int: " << number << std::endl;
}

void Converter::convertToFloat(const std::string& input)
{
    if (isPseudoLiteral(input))
    {
        if (input == "nan" || input == "+inf" || input == "-inf")
            std::cout << "float: " << input << "f" << std::endl;
        else
            std::cout << "float: " << input << std::endl;
        return;
    }
    if (isNotDigit(input))
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    float number = atof(input.c_str());
    std::cout << "float: " << std::fixed << std::setprecision(1)<< number << "f" << std::endl;
}   

void Converter::convertToDouble(const std::string& input)
{
    if (isPseudoLiteral(input))
    {
        if (input == "nanf" || input == "+inff" || input == "-inff")
            std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
        else
            std::cout << "double: " << input << std::endl;
        return;
    }
    
   else if (isNotDigit(input))
    {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    double number = atof(input.c_str());
    std::cout << std::fixed << "double: " << std::setprecision(1) << number << std::endl;
}

bool Converter::isNotDigit(const std::string& input)
{
    int len = input.size();
    bool dotFound = false;

    for (int i = 0; i < len; i++)
    {
        char c = input[i];

        if (i == 0 && (c == '-' || c == '+'))
            continue;

        if (c >= '0' && c <= '9')
            continue;

        if (c == '.')
        {
            if (dotFound)
                return true;
            dotFound = true;
            continue;
        }

        if (c == 'f' && i == len - 1)
            continue;

        return true;
    }
    return false;
}
