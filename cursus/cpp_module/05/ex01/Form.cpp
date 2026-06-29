/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:12:53 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/11 21:58:42 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


/*
 * -------------------------- Constructor --------------------------
 */

Form::Form(void) : name("untitled"), signFlag(false), signGrade(150), executeGrade(150)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int executeGrade) : \
		name(name), signFlag(false), signGrade(signGrade), executeGrade(executeGrade)
{
	std::cout << "Form constructor called" << std::endl;
	validateGrade(signGrade);
	validateGrade(executeGrade);
}

Form::Form(const Form& origin) : name(origin.getName()), signFlag(origin.getSignFlag()), \
							signGrade(origin.getSignGrade()), executeGrade(origin.getExecuteGrad())
{
	std::cout << "Form copy constructor called" << std::endl;
	validateGrade(origin.getSignGrade());
	validateGrade(origin.getExecuteGrad());
}

/*
 * -------------------------- Destructor ---------------------------
 */

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

Form& Form::operator=(const Form& origin)
{
	validateGrade(origin.getSignGrade());
	validateGrade(origin.getExecuteGrad());
	if (this != &origin)
		this->signFlag = origin.getSignFlag();	
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const Form& origin)
{
	out << "Form (" << origin.getName() << "): signFlag = " << std::boolalpha << origin.getSignFlag() \
		<< ", signGrade = " << origin.getSignGrade() << ", executeGrade = " << origin.getExecuteGrad();
	return out;
}

/*
 * -------------------------- Getter -------------------------------
 */

const std::string	Form::getName(void) const
{
	return this->name;
}

bool	Form::getSignFlag(void) const
{
	return this->signFlag;
}

int	Form::getSignGrade(void) const
{
	return this->signGrade;
}

int	Form::getExecuteGrad(void) const
{
	return this->executeGrade;
}

/*
 * -------------------------- Overriding ---------------------------
 */

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade over highest";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade over lowest";
}

Form::RequiredGradeException::RequiredGradeException(std::string bureaucratName, \
		std::string formName)
{
	this->message = "[ " + bureaucratName + " couldn't sign " + formName \
			+ " because " + bureaucratName + " grade is lower than the required grade ]";
}

Form::RequiredGradeException::~RequiredGradeException(void) throw() {}

const char* Form::RequiredGradeException::what() const throw()
{
	return this->message.c_str();
}

/*
 * -------------------------- Function -----------------------------
 */

bool	Form::beSigned(const Bureaucrat& bureaucrat)
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
		throw Form::RequiredGradeException(bureaucrat.getName(), this->getName());
}
