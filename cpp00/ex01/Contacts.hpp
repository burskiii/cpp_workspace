#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <iomanip>

class Contact {
	
	public:
		void set_contact();
		void display_contact(int index);
		void display_all(int index);
		std::string formatString(const std::string &str);

	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string secret;
};

#endif
