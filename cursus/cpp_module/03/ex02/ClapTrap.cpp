/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:11:19 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/05 16:46:36 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

ClapTrap::ClapTrap(void)
{
	this->name = "anonymity";
	this->hit = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "ClapTrap " << this->name << " was born!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "ClapTrap " << this->name << " was born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& origin)
{
	this->name = origin.name;
	this->hit = origin.hit;
	this->energy = origin.energy;
	this->damage = origin.damage;
	std::cout << "ClapTrap " << this->name << " was copied" << std::endl;
}

/*
 * -------------------------- Destructor -----------------------------
 */

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " was destructed" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

ClapTrap&	ClapTrap::operator=(const ClapTrap& origin)
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->hit <= 0 || this->energy <= 0)	
		return;
	this->energy--;	
	std::cout << "ClapTrap " << this->name << " attacks " << target \
		<< ", causing " << this->damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->hit -= amount;
	std::cout << "ClapTrap " << this->name << " was attacked and losts hits point as "\
	   	<< amount << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit <= 0 || this->energy <= 0)	
		return;
	this->hit += amount;	
	std::cout << "ClapTrap " << this->name << " reapired and recovered hits point as "\
	   	<< amount << std::endl;
}
