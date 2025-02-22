/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:23:37 by ygao              #+#    #+#             */
/*   Updated: 2025/02/22 16:59:10 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"

Phonebook::Phonebook() : contact_count(0) {} //is this a global variable? what is this line about?

void Phonebook::add()
{
	int index;

	index =  contact_count % 8;
	contact[index].set_contact();
	contact_count++;
}

void Phonebook::search()
{
	if (contact_count == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}

	int index;

	index = 0;
	while (index < contact_count)
	{
		contact[index].display_contact();
	}
}

void Phonebook::exit()
{
	std::cout << "Exiting phonebook" << std::endl;
	exit(); //does this exist in cpp? do i have to destry the phonebook here?
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
		}
	}
}
