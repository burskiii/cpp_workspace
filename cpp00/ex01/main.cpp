/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:38:00 by ygao              #+#    #+#             */
/*   Updated: 2025/03/25 12:28:32 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main() 
{
	Phonebook phonebook;//here small letter phonebook is a instance;

	phonebook.run(); //how to add a function here?
	return 0;
}
// The output of this program is:
// phonebook created
// phonebook destroyed
// This is because the phonebook instance is created when the program starts and destroyed when the program ends.
// The constructor and destructor are called automatically when the instance is created and destroyed.
// The constructor is called when the instance is created and the destructor is called when the instance is destroyed.
