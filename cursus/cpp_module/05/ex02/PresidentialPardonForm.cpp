/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:48:55 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/12 13:48:29 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/*
 * -------------------------- Constructor --------------------------
 */

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidentialPardonForm", this->requiredSign, this->requiredExec), target("target")
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidentialPardonForm", this->requiredSign, this->requiredExec), target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origin) : AForm(origin)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	validateGrade(origin.getSignGrade());
	validateGrade((origin.getExecuteGrad()));
}

/*
 * -------------------------- Destructor ---------------------------
 */

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& origin)
{
	validateGrade(origin.getSignGrade());
	validateGrade((origin.getExecuteGrad()));
	if (this != &origin)
		*this = origin;
	return *this;
}

/*
 * -------------------------- Getter -------------------------------
 */

std::string	PresidentialPardonForm::getTarget(void)
{
	return this->target;
}

/*
 * -------------------------- Function -----------------------------
 */

void	PresidentialPardonForm::execute(Bureaucrat const& executor)
{
	(void)executor;
	std::cout << "[ Zaphod Beeblebrox pardoned the " << this->getTarget() << " ]" << std::endl;
}

