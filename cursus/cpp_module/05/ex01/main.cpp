/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:05 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/10 23:20:13 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << std::endl << "==================" << std::endl;
	std::cout << "[ Form low test ]" << std::endl;
	try {
		for (int i = 149; i <= 151; ++i) {
			Form form("test", i, 1);
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "==================" << std::endl;
	try {
		for (int i = 149; i <= 151; ++i) {
			Form form("test", 1, i);
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "==================";
	std::cout << std::endl << "[ Form high test ]" << std::endl;
	try {
		for (int i = 2; i >= 0; --i) {
			Form form("test", 1, i);
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "==================" << std::endl;
	try {
		for (int i = 2; i >= 0; --i) {
			Form form("test", i, 1);
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "==================" << std::endl;
	std::cout << "[ Form Sign test ]" << std::endl;
	try {
		Bureaucrat bureaucrat("🙂 smile man", 42);
		Form form("🧾 paper", 40, 40);
		bureaucrat.increaseGrade();
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "==================" << std::endl;
	try {
		Bureaucrat bureaucrat("🙂 smile man", 42);
		Form form("🧾 paper", 40, 40);
		bureaucrat.increaseGrade(2);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
