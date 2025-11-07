#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <iomanip>

class Converter
{
    public:
        Converter();
        ~Converter();

        void convertToChar(const std::string& input);
        void convertToInt(const std::string& input);
        void convertToFloat(const std::string& input);
        void convertToDouble(const std::string& input);
        void pseudoLiteral(const std::string& input);
        bool isNotDigit(const std::string& input);
        bool isPseudoLiteral(const std::string& input);
        bool nonDisplayableChar(const std::string& input);
        
    private:
        bool dotFound;

    };
    



#endif