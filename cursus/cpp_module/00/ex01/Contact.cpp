/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 20:48:41 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/26 18:30:56 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cctype>

void	Contact::SetInfo(void)	
{
	std::cout << "enter first name:" << std::endl;	
	Contact::getlineEof(this->first_name);
	std::cout << "enter last name:" << std::endl;	
	Contact::getlineEof(this->last_name);
	std::cout << "enter nickname:" << std::endl;	
	Contact::getlineEof(this->nickname);
	std::cout << "enter phone number:" << std::endl;	
	Contact::getlineEof(this->phone_number);
	std::cout << "enter darkest secret:" << std::endl;	
	Contact::getlineEof(this->darkest_secret);
}

void Contact::PrintField(std::string field)
{
	if (field.length() <= 10)
	{
		for (size_t i = 0; i < 10 - field.length(); i++)
			std::cout << " ";
		std::cout << field;
	}
	else
	{
		for (int i = 0; i < 9; i++)
			std::cout << field.at(i);
		std::cout << ".";
	}
	std::cout << "|";
}

void	Contact::PrintFieldDetail(void)
{
	std::cout << "first name: " << this->first_name << std::endl;
	std::cout << "last name: " << this->last_name << std::endl;
	std::cout << "nickname: " << this->nickname << std::endl;
	std::cout << "phone number: " << this->phone_number << std::endl;
	std::cout << "darkest secret: " << this->darkest_secret << std::endl;
}

void	Contact::PrintInfo(void)
{
	PrintField(this->first_name);
	PrintField(this->last_name);
	PrintField(this->nickname);
	std::cout << std::endl;
}

void	Contact::getlineEof(std::string& input)
{
	if (std::getline(std::cin, input).eof() == true)
	{
		std::cout << "exit: eof" << std::endl;
		std::exit(1);
	}
}

bool	Contact::ValidateField(std::string& field)
{
	if (this->first_name.empty() == true)
		return false;
	for (size_t i = 0; i < field.length(); i++)
	{
		if (std::isspace(field.at(i)) == true)
			continue;
		else
		{
			ReplaceSpace(field);
			return true;
		}
	}
	return false;
}

bool	Contact::ValidateContact(void)
{
	if (ValidateField(this->first_name) == false)
		return false;
	if (ValidateField(this->last_name) == false)
		return false;
	if (ValidateField(this->nickname) == false)
		return false;
	if (ValidateField(this->phone_number) == false)
		return false;
	if (ValidateField(this->darkest_secret) == false)
		return false;
	return true;
}

void	Contact::ReplaceSpace(std::string& field)
{
	for (size_t i = 0; i < field.length(); i++)
	{
		if (std::isspace(field.at(i)) == true)
			field.replace(i, 1, " ");
	}
}
