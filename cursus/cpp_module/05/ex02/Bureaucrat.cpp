/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:47:40 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/12 13:42:21 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

Bureaucrat::Bureaucrat(void) : name("noname")
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	validateGrade(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& origin) : name(origin.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	validateGrade(origin.getGrade());
	this->grade = origin.getGrade();
}

/*
 * -------------------------- Destructor -----------------------------
 */

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	validateGrade(origin.getGrade());
	if (this != &origin)
		this->grade = origin.getGrade();
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

/*
 * -------------------------- Getter -------------------------------
 */

const std::string	Bureaucrat::getName(void) const
{
	return this->name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->grade;
}

/*
 * -------------------------- Overriding ---------------------------
 */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade over highest";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade over lowest";
}

/*
 * -------------------------- Function -----------------------------
 */

void	Bureaucrat::increaseGrade(void)
{
	validateGrade(this->grade - 1);
	this->grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	validateGrade(this->grade + 1);
	this->grade++;
}

void	Bureaucrat::increaseGrade(int grade)
{
	validateGrade(this->grade - grade);
	this->grade -= grade;
}

void	Bureaucrat::decreaseGrade(int grade)
{
	validateGrade(this->grade + grade);
	this->grade += grade;
}

void	validateGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& form)
{
	if (form.beSigned(*this) == true)
		std::cout << "[ " << this->name << " signed " << form.getName() << " ]" << std::endl;
	else
		std::cout << "[ " << form.getName() << " already signed" << " ]" << std::endl;
}

void	Bureaucrat::executeForm(AForm & form)
{
	if (form.getSignFlag() == false)
		throw AForm::NotSignedException();
	if (this->getGrade() > form.getExecuteGrad())
		throw AForm::RequiredGradeException(this->getName(), form.getName(), "execute");
	form.execute(*this);
	std::cout << "[ " << this->getName() << " executed " << form.getName() << " ]" << std::endl;
}
