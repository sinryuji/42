/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:54:54 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/05 17:28:35 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap hyeongki("hyeongki");
	ClapTrap enemy("enemy");

	hyeongki.attack("enemy");
	enemy.takeDamage(0);
	enemy.beRepaired(1);
	enemy.attack("hyeongki");
	hyeongki.takeDamage(0);
	enemy.attack("hyeongki");
	enemy.attack("hyeongki");
	enemy.attack("hyeongki");
	enemy.attack("hyeongki");
	enemy.attack("hyeongki");
	enemy.attack("hyeongki");
	enemy.attack("hyeongki");
	enemy.attack("hyeongki");
	enemy.attack("hyeongki");
	enemy.beRepaired(1);
	return 0;
}
