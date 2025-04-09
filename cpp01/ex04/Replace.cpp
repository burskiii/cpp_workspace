#include "Replace.hpp"


void replaceContent(std::string& filename, std::string& s1, std::string& s2)
{
	

}

void getFileContent(std::string& filename, std::string& s1)
{
	std::ifstream file(filename.c_str()); //opens a file for reading, and the c_str() is for C-style string - which is a pointer to a null-terminated array of characters.
	if (!file.is_open())
	{
		std::cout << "Error: File not found." << std::endl;
		return ;
	}
	std::string line;
	while (std::getline(file, line))
	{
		s1 += line + "\n"; //adds a new line character at the end of each line
	}
	if (s1.empty())
	{
		std::cout << "Error: File is empty." << std::endl;
		return ;
	}
	file.close();
}

void copyContentToFile(std::string& filename, std::string& content))
{
	std::ofstream file(filename);
	if (!file.is_open())
	{
		std::cout << "Error: File not found." << std::endl;
		return ;
	}

}
