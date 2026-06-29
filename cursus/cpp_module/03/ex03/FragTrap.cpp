/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:37:02 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/05 17:43:00 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

FragTrap::FragTrap(void) : ClapTrap()
{
	this->name = "anonymity";
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap " << this->name << " was born!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap " << this->name << " was born!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& origin) : ClapTrap(origin)
{
	this->name = origin.name;
	this->hit = origin.hit;
	this->energy = origin.energy;
	this->damage = origin.damage;
	std::cout << "FragTrap " << this->name << " was copied" << std::endl;
}

/*
 * -------------------------- Destructor -----------------------------
 */

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " was destructed" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

FragTrap&	FragTrap::operator=(const FragTrap& origin)
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

void	FragTrap::highFivesGuys(void)
{
	if (this->hit <= 0 || this->energy <= 0)	
		return;
	std::cout << "FragTrap " << this->name << " gave a high five" << std::endl;
}
