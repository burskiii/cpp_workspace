#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>//isprint
#include <cstdlib> //strtod, strtol
#include <iomanip> //setpercision
#include <climits> //limits
#include <cerrno> //errno

class ScalarConverter
{
    public:
    static void convert(const std::string& input);

    private:
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);

};

#endif