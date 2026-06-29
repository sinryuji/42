/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:00:09 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/12 14:37:47 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
 * -------------------------- Constructor --------------------------
 */

Intern::Intern(void)
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& origin)
{
	(void)origin;
	std::cout << "AForm copy constructor called" << std::endl;
}

/*
 * -------------------------- Destructor ---------------------------
 */

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

Intern& Intern::operator=(const Intern& origin)
{
	if (this != &origin)
		*this = origin;
	return *this;
}

/*
 * -------------------------- Function -----------------------------
 */

const char* Intern::MakeFormException::what() const throw()
{
	return "That Form do not exist";
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm* ret;
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 0;
	while (i < 3)
	{
		if (forms[i] == name)	
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			ret = new ShrubberyCreationForm(target);
			break;

		case 1:
			ret = new RobotomyRequestForm(target);
			break;

		case 2:
			ret = new PresidentialPardonForm(target);
			break;

		default:
			throw Intern::MakeFormException();
	}
	std::cout << "Intern creates " << name << std::endl;
	return ret;
}
