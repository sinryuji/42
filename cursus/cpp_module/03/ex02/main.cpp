/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:54:54 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/05 16:47:25 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap hyeongki("hyeongki");
	FragTrap enemy("enemy");

	enemy.highFivesGuys();
	hyeongki.attack("enemy");
	enemy.takeDamage(20);
	enemy.beRepaired(10);
	enemy.attack("hyeongki");
	hyeongki.takeDamage(30);
	hyeongki.beRepaired(30);
	return 0;
}
