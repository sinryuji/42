/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:50:04 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/06 02:49:40 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& origin) : Animal(origin)
{
	this->type = origin.getType();
	this->brain = new Brain();
	*this->brain = *origin.getBrain();
	std::cout << "Cat copy constructor called" << std::endl;
}

/*
 * -------------------------- Destructor -----------------------------
 */

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

/*
 * -------------------------- Operator -----------------------------
 */

Cat& Cat::operator=(const Cat& origin)
{
	if (this != &origin)
	{
		this->type = origin.getType();
		*this->brain = *origin.getBrain();
	}
	return *this;
}

/*
 * -------------------------- Function -----------------------------
 */

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return this->brain;	
}
