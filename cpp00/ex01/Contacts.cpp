#include "Contacts.hpp"


void Contact::set_contact( void ) 
{
	std::cout << "Give your first name:" << std::endl;
	std::cin >> this->first_name;
	std::cout << "Give your last name:" << std::endl;
	std::cin >> this->last_name;
	std::cout << "Give your nick name:" << std::endl;
	std::cin >> this->nick_name;
	std::cout << "Give your phone number:" << std::endl;
	std::cin >> this->phone_number;
	std::cout << "Give your darkest secret:" << std::endl;
	std::cin >> this->secret;
	std::cout << "Contact added" << std::endl;
}

std::string Contact::formatString(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void Contact::display_contact( int index )
{
	if (this->first_name == "")
	{
		return ;
	}
	std::cout << " | " << std::setw(10) << std::right  << index << " | "  
			<<std::setw(10) << std::right << formatString(this->last_name) << " | " 
			<<std::setw(10) << std::right << formatString(this->nick_name) << " | " 
			<<std::setw(10) << std::right << formatString(this->phone_number) << " | " 
			<< std::endl;
}
