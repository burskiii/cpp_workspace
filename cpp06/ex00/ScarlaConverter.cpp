#include "ScarlaConverter.hpp"

bool isPseudoLiteral(const std::string& input)
{
    return (input == "nan" || input == "+inf" || 
            input == "-inf" || input == "nanf" || 
            input == "+inff" || input == "-inff");
}

void ScarlaConverter::convert(const std::string& input)
{
    if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
    {
        char c = input[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        return;
    }
    if(input.size() == 1 && !std::isdigit(input[0]))
    {
        char c = input[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        return;
    }
    
    if (isPseudoLiteral(input))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (input == "nan" || input == "+inf" || input == "-inf")
        {
            std::cout << "float: " << input << "f" << std::endl;
            std::cout << "double: " << input << std::endl;
        }
        else
        {
            std::cout << "float: " << input.substr(0, input.size() - 1) << "f" << std::endl;
            std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
        }
        return;
    }

    // ---------- numeric parsing ----------
    errno = 0;
    char* end = 0;
    double value = std::strtod(input.c_str(), &end);

    // allow trailing 'f' only as the last character (float literal)
    bool ok = false;
    if (end && *end == '\0')
        ok = true;
    else if (end && *end == 'f' && *(end + 1) == '\0')
        ok = true;

    // reject inputs like ".", "+.", "-", "f", "1f"?? (1f should be invalid per "most common form")
    if (ok)
    {
        // disallow empty numeric part such as "." or "+."
        // strtod would parse "." as 0 and end == input.c_str(), we want invalid
        if (end == input.c_str())
            ok = false;
    }

    if (!ok || errno == ERANGE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // ---------- char output ----------
    if (value < 0.0 || value > 127.0)
    {
        std::cout << "char: impossible" << std::endl;
    }
    else if (!std::isprint(static_cast<unsigned char>(static_cast<int>(value))))
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }

    // ---------- int output ----------
    if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    // ---------- float & double output ----------
    std::cout << std::fixed << std::setprecision(1);

    // For float, even huge doubles might overflow to inf; that's acceptable output-wise
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

ScarlaConverter::ScarlaConverter() {}
ScarlaConverter::~ScarlaConverter() {}
ScarlaConverter::ScarlaConverter(const ScarlaConverter& other) { (void)other
; }
ScarlaConverter& ScarlaConverter::operator=(const ScarlaConverter& other)
{
    (void)other;
    return *this;
}