#include "Converter.hpp"


// forward declarations (ensures the helper functions are visible to member definitions)
bool isWithPoint(const std::string& input);
bool isNotDigit(const std::string& input);


Converter::Converter() {}

Converter::~Converter() {}

bool Converter::isPseudoLiteral(const std::string& input)
{
    return (input == "nan" || input == "+inf" || 
            input == "-inf" || input == "nanf" || 
            input == "+inff" || input == "-inff");
}

// bool Converter::isValidNumber(const std::string &input)
// {
//     if (input.empty())
//         return false;

//     size_t i = 0;
//     if (input[i] == '+' || input[i] == '-')
//         ++i;

//     bool hasDigit = false;
//     bool hasDot = false;
//     bool hasF = false;

//     for (; i < input.size(); ++i)
//     {
//         char c = input[i];
//         if (std::isdigit(static_cast<unsigned char>(c)))
//         {
//             hasDigit = true;
//             continue;
//         }
//         if (c == '.')
//         {
//             if (hasDot || hasF)
//                 return false;
//             hasDot = true;
//             continue;
//         }
//         if (c == 'f')
//         {
//             if (hasF || i != input.size() - 1 || !hasDigit)
//                 return false;
//             hasF = true;
//             continue;
//         }
//         return false; // invalid character
//     }
//     return hasDigit;
// }


void Converter::convertToChar(const std::string& input)
{
    if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
    {
        std::cout << "char: '" << input[0] << "'" << std::endl;
        return;
    }

    // nan, inf
    if (isPseudoLiteral(input))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    // invalid input
    if (isNotDigit(input))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    // convert to int and check range
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
    if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    else if ((isNotDigit(input)) == true)
    {
        std::cout << "int: impossible" << std::endl;
    }
    else if (hasSignOrPoint(input) && isNotDigit(input) == false)
    {
        int number = floatToInt(input);
        if (isNegative)
            number = -number;
        std::cout << "int: " << number << std::endl;
        return;
    }
    else
    {
        std::stringstream converter;
        converter << input;
        int number;
        converter >> number;
        std::cout << "int: " << number << std::endl;
    }
}

void Converter::convertToFloat(const std::string& input)
{
    if (input == "nan" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
    {
        if (input == "+inff" || input == "-inff")
            std::cout << "float: " << input << std::endl;
        else
            std::cout << "float: " << input << "f" << std::endl;
        return;
    }
    else if (isNotDigit(input) == true)
    {
        std::cout << "float: impossible" << std::endl;
    }
    else if (isFloat == true && isNotDigit(input) == false)
    {
        float number = atof(input.c_str());
        std::cout << "float: " << std::fixed << std::setprecision(1)<< number << "f" << std::endl;
    }
    else
    {
        float number = atof(input.c_str());
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << number << "f" << std::endl;
    }
}   

void Converter::convertToDouble(const std::string& input)
{
    if (input == "nan" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
    {
        if (input == "+inff" || input == "-inff")
            std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
        else
        std::cout << "double: " << input.substr(0, input.length()) << std::endl;
        return;
    }
   else if (isNotDigit(input) == true)
    {
        std::cout << "double: impossible" << std::endl;
    }
    else
    {
        double number = atof(input.c_str());
        std::cout << std::fixed << "double: " << std::setprecision(1) << number << std::endl;
    }
}

bool Converter::isWithPoint(const std::string& input)
{
    for (int i = 0; input[i]; i++)
    {
        if ((input[i] == '.') && (input[(input.size()) - 1] == 'f'))
        {
            if (isNotDigit(input) == false)
            {
                isFloat = true;
                return true;
            }
        }
    }
    return false;
}

bool Converter::isNotDigit(const std::string& input)
{
    int len = input.size();

    for (int i = 0; input[i]; i++)
    {
        char c = input[i];
        int j = 0;
        if (input[0] == '-' || input[0] == '+')
        {
            i++;
            if (input[i]  == '-' || input[0] == '+')
                return true;
            else   
                continue;
        }
        if (c >= '0' && c <= '9')
            continue;
        if (c == '.')
        {
            isFloat = true;
            j++;
            continue;
        }
        if (c == 'f' && i == len - 1)
            continue;
        else if (static_cast<int>(static_cast<unsigned char>(input[i]) > 127))
        {
            return true;
        }
        else if ((input[i] < '0' || input[i] > '9') && input[i] != '.' && input[len - 1] != 'f')
        {
            // std::cout << "Debug: found non-digit character: " << input[i] << std::endl;
            return true;
        }
        else if (j > 1)
        {
            return true;
        }
        else if (input == "nan" || input == "+inf" || input == "-inf" || input == "nanf" || input == "+inff" || input == "-inff")
            return false;
        else 
            return true;

    }
    return false;
}

bool Converter::hasSignOrPoint(const std::string& input)
{
    for (int i = 0; input[i]; i++)
    {
        if (input[i] == '.' || input[i] == '-' || input[i] == '+')
        {
            if (input[i] == '-')
                isNegative = true;
            if (input[i] == '+')
                isPositive = true;
        }
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