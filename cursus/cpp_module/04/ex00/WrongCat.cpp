/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:50:04 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/06 00:44:24 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& origin) : WrongAnimal(origin)
{
	this->type = origin.getType();
	std::cout << "WrongCat copy constructor called" << std::endl;
}

/*
 * -------------------------- Destructor -----------------------------
 */

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

WrongCat& WrongCat::operator=(const WrongCat& origin)
{
	if (this != &origin)
		this->type = origin.getType();
	return *this;
}

/*
 * -------------------------- Function -----------------------------
 */

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow...?" << std::endl;
}
