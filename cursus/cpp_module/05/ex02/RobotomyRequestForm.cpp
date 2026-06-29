/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:48:55 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/12 13:48:08 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/*
 * -------------------------- Constructor --------------------------
 */

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomyRequestForm", this->requiredSign, this->requiredExec), target("target")
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomyRequestForm", this->requiredSign, this->requiredExec), target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin) : AForm(origin)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	validateGrade(origin.getSignGrade());
	validateGrade((origin.getExecuteGrad()));
}

/*
 * -------------------------- Destructor ---------------------------
 */

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& origin)
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

std::string	RobotomyRequestForm::getTarget(void)
{
	return this->target;
}

/*
 * -------------------------- Function -----------------------------
 */

void	RobotomyRequestForm::execute(Bureaucrat const& executor)
{
	(void)executor;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << "[ " << this->getTarget() << " robotomized succeed!! ]" << std::endl;
	else
		std::cout << "[ " << this->getTarget() << " robotomized fail!! ]" << std::endl;
}
