/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:23:39 by ygao              #+#    #+#             */
/*   Updated: 2025/03/25 13:41:14 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
