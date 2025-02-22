/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:03:19 by ygao              #+#    #+#             */
/*   Updated: 2025/02/22 17:05:43 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"


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

void Contact::display_contact( void )
{
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nick name: " << this->nick_name << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Secret: " << this->secret << std::endl;
	
}
