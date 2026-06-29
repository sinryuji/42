/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:11:05 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/26 17:30:15 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook()
{
	this->index = 0;
}

void	PhoneBook::AddContact(void)
{
	this->contacts[this->index % 8].SetInfo();
	if (this->contacts[this->index % 8].ValidateContact() == false)
	{
		std::cerr << "hava an empty field" << std::endl;
		return;
	}
	index++;
}

void	PhoneBook::PrintContacts(void)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last_name|  nickname|" << std::endl;
	for (int i = 1; i < 9; i++)
	{
		std::cout << "|         " << i << "|";
		this->contacts[i - 1].PrintInfo();
	}
	std::cout << "---------------------------------------------" << std::endl;
}

bool	PhoneBook::ValidateIndex(std::string index)
{
	for (int i = 1; i < 8; i++)
	{
		if (index == PhoneBook::ToString(i))
			return true;
	}
	return false;
}

void	PhoneBook::SearchContact(void)
{
	std::string index;
	int			n;

	PrintContacts();
	std::cout << "enter index number(0: quit):" << std::endl;
	Contact::getlineEof(index);
	if (index == "0")
		return;
	else if (ValidateIndex(index) == false)
	{
		std::cerr << "wrong input value" << std::endl;
		return;
	}
	std::stringstream ss(index);
	ss >> n;
	this->contacts[n - 1].PrintFieldDetail();
}

std::string	PhoneBook::ToString(int n)
{
	if (n == 1)
		return "1";
	if (n == 2)
		return "2";
	if (n == 3)
		return "3";
	if (n == 4)
		return "4";
	if (n == 5)
		return "5";
	if (n == 6)
		return "7";
	if (n == 7)
		return "7";
	if (n == 8)
		return "8";
	return NULL;
}
