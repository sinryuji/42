/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:51:30 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/06 11:44:45 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& origin) : type(origin.getType())
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/*
 * -------------------------- Destructor -----------------------------
 */

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

Animal& Animal::operator=(const Animal& origin)
{
	if (this != &origin)
		this->type = origin.getType();
	return *this;
}

/*
 * -------------------------- Function -----------------------------
 */

std::string	Animal::getType(void) const
{
	return this->type;
}
