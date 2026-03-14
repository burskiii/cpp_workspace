#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange bitcoinExchange;

    bitcoinExchange.readDatabase();
    //bitcoinExchange.debugPrinter();
    bitcoinExchange.evaluate(argv[1]);
    return 0;
}   