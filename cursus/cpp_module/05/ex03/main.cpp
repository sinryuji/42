/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:05 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/12 14:39:33 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern intern = Intern();

	try {
		AForm* form = intern.makeForm("test", "test");
		Bureaucrat bur = Bureaucrat("test", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================\n" << std::endl;

	try {
		AForm* form = intern.makeForm("ShrubberyCreationForm", "SCF");
		Bureaucrat bur = Bureaucrat("test", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================\n" << std::endl;

	try {
		AForm* form = intern.makeForm("RobotomyRequestForm", "RRF");
		Bureaucrat bur = Bureaucrat("test", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n====================================\n" << std::endl;

	try {
		AForm* form = intern.makeForm("PresidentialPardonForm", "PPF");
		Bureaucrat bur = Bureaucrat("test", 1);
		bur.signForm(*form);
		bur.executeForm(*form);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
