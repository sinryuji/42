/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:32:45 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/05 17:59:03 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->name = "anonymity";
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap " << this->name << " was born!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap " << this->name << " was born!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& origin) : ClapTrap(origin)
{
	this->name = origin.name;
	this->hit = origin.hit;
	this->energy = origin.energy;
	this->damage = origin.damage;
	std::cout << "ScavTrap " << this->name << " was copied" << std::endl;
}

/*
 * -------------------------- Destructor -----------------------------
 */

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " was destructed" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

ScavTrap&	ScavTrap::operator=(const ScavTrap& origin)
{
	if (this != &origin)	
	{
		this->name = origin.name;
		this->hit = origin.hit;
		this->energy = origin.energy;
		this->damage = origin.damage;
	}
	return *this;
}

/*
 * -------------------------- Function -----------------------------
 */

void	ScavTrap::attack(const std::string& target)
{
	if (this->hit <= 0 || this->energy <= 0)	
		return;
	this->energy--;	
	std::cout << "ScavTrap " << this->name << " attacks " << target \
		<< ", causing " << this->damage << " points of damage!" << std::endl;
}


void	ScavTrap::guardGate(void)
{
	if (this->hit <= 0 || this->energy <= 0)	
		return;
	std::cout << "ScavTrap " << this->name << " is Gate kepper mode" << std::endl;
}
