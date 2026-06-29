/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:05 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/10 23:02:49 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << std::endl << "==================" << std::endl;
	std::cout << "[ Bureaucrat low test ]" << std::endl;
	try {
		Bureaucrat b1 = Bureaucrat("b1", 100);
		Bureaucrat b2 = Bureaucrat("b2", 151);
		std::cout << "in?" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "==================" << std::endl;
	std::cout << "[ Bureaucrat high test ]" << std::endl;
	try {
		Bureaucrat b3 = Bureaucrat("b3", 100);
		Bureaucrat b4 = Bureaucrat("b4", 0);
		std::cout << "in?" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "==================" << std::endl;
	std::cout << "[ increase test ]" << std::endl;
	try {
		Bureaucrat b5 = Bureaucrat("b5", 2);
		b5.increaseGrade();
		std::cout << b5 << std::endl;
		b5.increaseGrade();
		std::cout << b5 << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "==================" << std::endl;
	std::cout << "[ decrease test ]" << std::endl;
	try {
		Bureaucrat b6 = Bureaucrat("b6", 149);
		b6.decreaseGrade();
		std::cout << b6 << std::endl;
		b6.decreaseGrade();
		std::cout << b6 << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
