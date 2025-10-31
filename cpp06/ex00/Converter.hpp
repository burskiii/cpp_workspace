#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>

class Converter
{
    public:
        Converter();
        // ~Converter();

        void convertToChar(const std::string& input);
        void convertToInt(const std::string& input);
        // void convertToFloat(const std::string& input);
        // void convertToDouble(const std::string& input);
        
        
        int floatToInt(const std::string& input);
        bool hasSignOrPoint(const std::string& input);
        bool isWithPoint(const std::string& input);
        bool isNotDigit(const std::string& input);

        
        private:
        // std::string _input;
        bool isFloat;
    };
    



#endif