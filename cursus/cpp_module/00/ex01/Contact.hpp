/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:27:05 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/26 18:26:13 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdlib>
# include <cctype>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		static void	PrintField(std::string field);

	public:
		void		SetInfo(void);
		void		PrintInfo(void);
		void		PrintFieldDetail(void);
		static void	getlineEof(std::string& input);
		bool		ValidateContact(void);
		bool		ValidateField(std::string& field);
		void		ReplaceSpace(std::string& field);
};

#endif
