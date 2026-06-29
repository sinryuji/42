/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:12:53 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/12 14:01:05 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
 * -------------------------- Constructor --------------------------
 */

AForm::AForm(void) : name("untitled"), signFlag(false), signGrade(150), executeGrade(150)
{
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade) : \
		name(name), signFlag(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "AForm constructor called" << std::endl;
	validateGrade(signGrade);
	validateGrade(executeGrade);
}

AForm::AForm(const AForm& origin) : name(origin.getName()), signFlag(origin.getSignFlag()), \
							signGrade(origin.getSignGrade()), executeGrade(origin.getExecuteGrad())
{
	std::cout << "AForm copy constructor called" << std::endl;
	validateGrade(origin.getSignGrade());
	validateGrade(origin.getSignGrade());
}

/*
 * -------------------------- Destructor ---------------------------
 */

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

AForm& AForm::operator=(const AForm& origin)
{
	validateGrade(origin.getSignGrade());
	validateGrade(origin.getExecuteGrad());
	if (this != &origin)
		this->signFlag = origin.getSignFlag();	
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const AForm& origin)
{
	out << "Form (" << origin.getName() << "): signFlag = " << std::boolalpha << origin.getSignFlag() \
		<< ", signGrade = " << origin.getSignGrade() << ", executeGrade = " << origin.getExecuteGrad();
	return out;
}

/*
 * -------------------------- Getter -------------------------------
 */

const std::string	AForm::getName(void) const
{
	return this->name;
}

bool	AForm::getSignFlag(void) const
{
	return this->signFlag;
}

int	AForm::getSignGrade(void) const
{
	return this->signGrade;
}

int	AForm::getExecuteGrad(void) const
{
	return this->executeGrade;
}

/*
 * -------------------------- Overriding ---------------------------
 */

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade over highest";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade over lowest";
}

AForm::RequiredGradeException::RequiredGradeException(std::string bureaucratName, \
		std::string formName, std::string behavior)
{
	this->message = "[ " + bureaucratName + " couldn't " + behavior + " " + formName \
			+ " because " + bureaucratName + " grade is lower than the required grade ]";
}

AForm::RequiredGradeException::~RequiredGradeException(void) throw() {}

const char* AForm::RequiredGradeException::what() const throw()
{
	return this->message.c_str();
}

const char* AForm::NotSignedException::what() const throw()
{
	return "[ This Form hasn't been signed yet ]";
}

/*
 * -------------------------- Function -----------------------------
 */

bool	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getSignGrade())
	{
		if (this->signFlag == false)
		{
			this->signFlag = true;
			return true;
		}
		else
			return false;
	}
	else
		throw AForm::RequiredGradeException(bureaucrat.getName(), this->getName(), "sign");
}
