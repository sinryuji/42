/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:54:54 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/05 17:36:15 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap hyeongki("hyeongki");
	ScavTrap enemy("enemy");
	ScavTrap hyeongki2(hyeongki);

	hyeongki.guardGate();
	hyeongki.attack("enemy");
	enemy.takeDamage(20);
	enemy.beRepaired(30);
	enemy.attack("hyeongki");
	hyeongki.takeDamage(20);
	hyeongki.beRepaired(30);
	return 0;
}
