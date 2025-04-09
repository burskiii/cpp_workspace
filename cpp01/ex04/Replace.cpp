#include "Replace.hpp"

//replace s1 with s2 in filename file
void replaceContent(std::string& filename, std::string& s1, std::string& s2)
{
	std::string content;
	getFileContent(filename, content); //get the content of the file
	if (content.empty())
	{
		std::cout << "Error: File is empty." << std::endl;
		return ;
	}
	std::string newContent;
	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos) //find s1 in the content
	{
		newContent += content.substr(0, pos) + s2; //replace s1 with s2
		content.erase(0, pos + s1.length()); //erase s1 from the content
	}
	newContent += content; //add the rest of the content
	copyContentToFile(filename, newContent); //copy the new content to the file

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
	while (std::getline(file, line)) //put line in the file?
	{
		s1 += line + "\n"; //adds a new line character at the end of each line
	}
	// if (s1.empty())
	// {
	// 	std::cout << "Error: File is empty." << std::endl;
	// 	return ;
	// }
	file.close();
}

//copy the content to the file
void copyContentToFile(std::string& filename, std::string& content)
{
	std::ofstream file(filename.c_str()); //opens a file for writing
	if (!file.is_open())
	{
		std::cout << "Error: File not found." << std::endl;
		return ;
	}
	file << content; //writes the content to the file
	file.close();
}
