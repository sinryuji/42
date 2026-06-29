/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:50:51 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/26 15:58:16 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	private:
		Contact		contacts[8];
		int			index;
		void		PrintContacts(void);
		bool		ValidateIndex(std::string index);
		std::string	ToString(int n);

	public:
		PhoneBook(void);
		void		AddContact(void);
		void		SearchContact(void);
};

#endif
