#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP	

#include "Contacts.hpp"

class Phonebook {
	
	public:
		Phonebook();
		~Phonebook();
		void	add( void );
		void	search( void );
		void	exit( void );
		void 	run( void );

	private:
		Contact contact[8];
		int contact_count;
		std::string command;
	
};

#endif
