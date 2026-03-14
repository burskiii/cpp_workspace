#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <algorithm>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void readDatabase();
        bool checkFile(const std::string& filename);
        bool isValidDate(std::string& date);
        bool isValidValue(std::string& value);
        void evaluate(const std::string& file);

        void debugPrinter() const;

    private:
        std::map<std::string, double> _database;
};

#endif