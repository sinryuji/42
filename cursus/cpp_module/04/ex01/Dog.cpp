/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:50:04 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/06 02:49:48 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& origin) : Animal(origin)
{
	this->type = origin.getType();
	this->brain = new Brain();
	*this->brain = *origin.getBrain();
	std::cout << "Dog copy constructor called" << std::endl;
}

/*
 * -------------------------- Destructor -----------------------------
 */

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

/*
 * -------------------------- Operator -----------------------------
 */

Dog& Dog::operator=(const Dog& origin)
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

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow!" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return this->brain;	
}
