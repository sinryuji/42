/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:47:40 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/06 16:15:50 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

/*
 * -------------------------- Function -----------------------------
 */

void	Bureaucrat::validateGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const std::string	Bureaucrat::getName(void) const
{
	return this->name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->grade;
}

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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade over highest";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade over lowest";
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
