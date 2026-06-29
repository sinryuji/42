/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:10:35 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/05 17:55:49 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	this->name = "anonymity";
	ClapTrap::name = this->name + "_clap_name";
	this->damage = 30;
	std::cout << "DiamondTrap " << this->name << " was born!" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	ClapTrap::name = name + "_clap_name";
	this->damage = 30;
	std::cout << "DiamondTrap " << this->name << " was born!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& origin) : ClapTrap(origin), FragTrap(origin), ScavTrap(origin)
{
	this->name = origin.name;
	this->hit = origin.hit;
	this->energy = origin.energy;
	this->damage = origin.damage;
	std::cout << "DiamondTrap " << this->name << " was copied" << std::endl;
}

/*
 * -------------------------- Destructor -----------------------------
 */

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->name << " was destructed" << std::endl;
}

/*
 * -------------------------- Operator -----------------------------
 */

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& origin)
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

void	DiamondTrap::whoAmI(void)
{
	std::cout	<< "This DiamondTrap name is " << this->name 
		<< " and This ClapTrap name is " << ClapTrap::name << std::endl;
}
