#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->_database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::readDatabase() 
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }

    std::string line;
    if (std::getline(file, line))
    {
        if (!line.empty() && line[line.length() - 1] == '\r')
           line.erase(line.length() - 1);
        if (line != "date,exchange_rate")
        {
           std::cerr << "Error: missing header => " << line << std::endl;
            return ;
        }
    }

    while (std::getline(file,line))
    {
        if (line.empty()) 
            continue;

        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
        {
            std::cerr << "Error: invalid line format => " << line << std::endl;
            continue ;  
        }
        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1); //+1 to skip the comma

        if (line.empty() || line.find_first_not_of(" \t\r\n") == std::string::npos)
             continue;
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        rateStr.erase(0, rateStr.find_first_not_of(" \t"));
        rateStr.erase(rateStr.find_last_not_of(" \t") + 1);

        float value = std::atof(rateStr.c_str());
        _database[date] = value;
    }
    file.close();
}   

// void BitcoinExchange::debugPrinter const() 
// {
//     std::map<std::string, double>::const_iterator it;
//     for (it = _database.begin(); it != _database.end(); ++it) {
//         std::cout << it->first << ": "  << std::fixed << std::setprecision(2) << it->second << std::endl;
//     }
// }

bool BitcoinExchange::checkFile(const std::string& filename) 
{
    if (filename.empty()) {
        std::cerr << "Error: filename is empty." << std::endl;
        return false;
    }   
    bool onlySpaces = true;
    for (size_t i = 0; i < filename.length(); ++i) {
        if (!std::isspace(filename[i])) {
            onlySpaces = false;
            break;
        }
    }
    if (onlySpaces) {
        std::cerr << "Error: filename contains only spaces" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(std::string& date) 
{
    std::istringstream ss(date);
    int year, month, day;
    char dash;
    
    //year
    ss >> year;
    if (year < 0 || year > 9999) 
    {
        std::cerr << "Error: invalid year => " << date << std::endl;
        return false;
    }
    ss >> dash;
    if (dash != '-')
    {
        std::cerr << "Error: invalid date format => " << date << std::endl;
        return false;
    }
    
    //month
    ss >> month;
    if (month < 1 || month > 12) 
    {
        std::cerr << "Error: invalid month => " << date << std::endl;
        return false;
    }
    ss >> dash;
    if (dash != '-')
    {
        std::cerr << "Error: invalid date format => " << date << std::endl;
        return false;  
    }
    
    //day
    ss >> day;
    if (month == 4 || month == 6 || month == 9 || month == 11) 
    {
        if (day < 1 || day > 30) 
        {
            std::cerr << "Error: invalid day => " << date << std::endl;
            return false;
        }
    } 
    else if (month == 2) 
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        int maxDay = isLeapYear ? 29 : 28;
        if (day < 1 || day > maxDay) 
        {
            std::cerr << "Error: invalid day => " << date << std::endl;
            return false;
        }
    } 
    else 
    {
        if (day < 1 || day > 31) 
        {
            std::cerr << "Error: invalid day => " << date << std::endl;
            return false;
        }
    }
    
    if (date.length() != 10) 
    {
        std::cerr << "Error: invalid date format => " << date << std::endl;
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if ((i == 4 || i == 7) && date[i] != '-') {
            std::cerr << "Error: invalid date format => " << date << std::endl;
            return false;
        }
        if (i != 4 && i != 7 && !isdigit(date[i])) {
            std::cerr << "Error: invalid date format => " << date << std::endl;
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::isValidValue(std::string& value) 
{

    if (value.empty()) {
        std::cerr << "Error: empty value" << std::endl;
        return false;
    }
    value.find(".");
    if ( value.find(".") == 0 || value.find(".") == value.length() - 1) {
        std::cerr << "Error: not a digit number" << std::endl;
        return false;
    }

    int decimalPointCount = std::count(value.begin(), value.end(), '.');
    if (decimalPointCount > 1) {
        std::cerr << "Error: not a digit number" << std::endl;
        return false;
    }

    for (std::string::const_iterator it = value.begin(); it != value.end(); ++it) {
        if (!isdigit(*it) && *it != '.') {  // Allow decimal points and negative signs
            std::cerr << "Error: not a digit number" << std::endl;
            return false;
        }
    }

    double val = std::atof(value.c_str());
    if (val < 0){
        std::cerr << "Error: not a positive number" << std::endl;
        return false;
    }
    if (val > 1000){
        std::cerr << "Error: too large a number" << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::evaluate(const std::string& file) 
{
    std::ifstream filename(file.c_str());
    if (!checkFile(file) || !filename.is_open()) 
    {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }
    
    std::string line;
    if (std::getline(filename,line))
    {
        if (line != "date | value")
        {
            if (!line.empty() && line[line.length() - 1] == '\r')
                line.erase(line.length() - 1);
            
            else
            std::cerr << "Error: missing header => " << line << std::endl;
            return ; //should it return here?
        }
    }
            
    float result;
    while (std::getline(filename, line))
    {
        if (line.empty()) 
        continue;
        
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) 
        {
            std::cerr << "Error: invalid line format => " << line << std::endl;
            continue ;
        }
        
        
        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1); //+1 to skip the pipe
        
        if (line.empty() || line.find_first_not_of(" \t\r\n") == std::string::npos)
            continue;
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
            
        if (!isValidDate(date) || !isValidValue(valueStr))
            continue;

        double value = std::atof(valueStr.c_str());
        if(_database.find(date) != _database.end()){
            result = _database[date] * value;
            std::cout << date << " => " << value << " = " << result << std::endl;
        } else {
            std::map<std::string, double>::const_iterator it;
            it = _database.lower_bound(date);
            if(it != _database.begin()){
                --it;
                result = it->second * value;
                std::cout << date << " => " << value << " = " << result << std::endl;
            } else {
                std::cerr << "No data for date: " << date << std::endl;
            }
        }    
    }
}
