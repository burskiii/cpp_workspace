#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Replace.hpp"

int main(int argc, char **argv)
{
	std::string source;
	std::string dest;
	std::string content;

	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <input_file> <output_file> <replacement_string>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.length() == 0)
	{
		std::cout << "Error: String s1 is empty." << std::endl;
		return 1;
	}

	replaceContent(filename, s1, s2);
	
	return 0;

}
