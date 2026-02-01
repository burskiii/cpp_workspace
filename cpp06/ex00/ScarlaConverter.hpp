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

class ScarlaConverter
{
    public:
    static void convert(const std::string& input);

    private:
    ScarlaConverter();
    ~ScarlaConverter();
    ScarlaConverter(const ScarlaConverter& other);
    ScarlaConverter& operator=(const ScarlaConverter& other);

};

#endif