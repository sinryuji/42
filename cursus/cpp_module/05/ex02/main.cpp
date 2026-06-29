/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:05 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/12 13:24:56 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	std::cout << "\n====================================" << std::endl;
	std::cout << "=====ShrubberyCreationForm Test=====" << std::endl;
	std::cout << "====================================\n" << std::endl;

	try {
		ShrubberyCreationForm scf = ShrubberyCreationForm("SCF");
		std::cout << scf << std::endl;
		Bureaucrat bur = Bureaucrat();
		bur.executeForm(scf);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================\n" << std::endl;

	try {
		ShrubberyCreationForm scf = ShrubberyCreationForm("SCF");
		std::cout << scf << std::endl;
		Bureaucrat bur = Bureaucrat("test", ShrubberyCreationForm::requiredSign);
		bur.signForm(scf);
		bur.executeForm(scf);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================\n" << std::endl;

	try {
		ShrubberyCreationForm scf = ShrubberyCreationForm("SCF");
		std::cout << scf << std::endl;
		Bureaucrat bur = Bureaucrat("test", ShrubberyCreationForm::requiredExec);
		bur.signForm(scf);
		bur.executeForm(scf);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================" << std::endl;
	std::cout << "=======RobotomyRequestForm Test=====" << std::endl;
	std::cout << "====================================\n" << std::endl;

	try {
		RobotomyRequestForm rrf = RobotomyRequestForm("RRF");
		std::cout << rrf << std::endl;
		Bureaucrat bur = Bureaucrat();
		bur.executeForm(rrf);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================\n" << std::endl;

	try {
		RobotomyRequestForm rrf = RobotomyRequestForm("RRF");
		std::cout << rrf << std::endl;
		Bureaucrat bur = Bureaucrat("test", RobotomyRequestForm::requiredSign);
		bur.signForm(rrf);
		bur.executeForm(rrf);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================\n" << std::endl;

	try {
		RobotomyRequestForm rrf = RobotomyRequestForm("RRF");
		std::cout << rrf << std::endl;
		Bureaucrat bur = Bureaucrat("test", RobotomyRequestForm::requiredExec);
		bur.signForm(rrf);
		bur.executeForm(rrf);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================" << std::endl;
	std::cout << "=====PresidentialPardonForm Test====" << std::endl;
	std::cout << "====================================\n" << std::endl;

	try {
		PresidentialPardonForm ppf = PresidentialPardonForm("PPF");
		std::cout << ppf << std::endl;
		Bureaucrat bur = Bureaucrat();
		bur.executeForm(ppf);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================\n" << std::endl;

	try {
		PresidentialPardonForm ppf = PresidentialPardonForm("PPF");
		std::cout << ppf << std::endl;
		Bureaucrat bur = Bureaucrat("test", PresidentialPardonForm::requiredSign);
		bur.signForm(ppf);
		bur.executeForm(ppf);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================\n" << std::endl;

	try {
		PresidentialPardonForm ppf = PresidentialPardonForm("PPF");
		std::cout << ppf << std::endl;
		Bureaucrat bur = Bureaucrat("test", PresidentialPardonForm::requiredExec);
		bur.signForm(ppf);
		bur.executeForm(ppf);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
