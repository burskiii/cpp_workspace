<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:23:37 by ygao              #+#    #+#             */
/*   Updated: 2025/04/01 11:00:07 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 723dec9 (update)
#include <iostream>
#include <string>
#include "Phonebook.hpp"

Phonebook::Phonebook() : contact_count(0)
{
	std::cout << "Your phonebook is ready" << std::endl;
	std::cout << "Command ADD: add new contact to phonebook" << std::endl;
	std::cout << "Command SEARCH: search for exicted contact from phonebook" << std::endl;
	std::cout << "Command EXIT: exit and clean phonebook" << std::endl;
	std::cout << "-------------------Let us start-------------------" << std::endl;
}

void Phonebook::add()
{
	int index;

	index =  contact_count % 8;
	contact[index].set_contact();
	if (contact_count < 8)
		contact_count++;
	else
		contact_count = 8;
		
}

void Phonebook::search()
{
	if (contact_count == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}
	std::cout << " | " << std::setw(10) << std::right << "Index" << " | " 
						<< std::setw(10) << std::right << "First Name" << " | "
				 		<< std::setw(10) << std::right << "Last Name" << " | "
						<< std::setw(10) << std::right << "Nickname" << " | "
						<< std::endl;
	for (int i = 0; i < contact_count; i++)
		contact[i].display_contact(i);
}

void Phonebook::run()
{
	while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> this->command;
		if (!(this->command == "add" || this->command == "ADD" || this->command == "search" || this->command == "SEARCH" || this->command == "exit" || this->command == "EXIT"))
		{
			std::cout << "Invalid command" << std::endl;
			continue;
		}
		if (this->command == "add" || this->command == "ADD")
		{
			Phonebook::add();
		}
		else if (this->command == "search" || this->command == "SEARCH")
		{
			Phonebook::search();
		}
		else if (this->command == "exit" || this->command == "EXIT")
		{
			Phonebook::exit();
			break;
		}
	}
}

void Phonebook::exit()
{
	std::cout << "Exiting phonebook" << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Your phonebook date has been cleaned" << std::endl;
}


