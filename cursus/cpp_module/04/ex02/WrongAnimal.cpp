/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:51:30 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/06 00:46:02 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& origin) : type(origin.getType())
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

/*
 * -------------------------- Destructor -----------------------------
 */

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& origin)
{
	if (this != &origin)
		this->type = origin.getType();
	return *this;
}

/*
 * -------------------------- Function -----------------------------
 */

void	WrongAnimal::makeSound(void) const
{
	std::cout << "This instance is WrongAnimal" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return this->type;
}
