/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:54:54 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/05 18:00:34 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap hyeongki("hyeongki");
	DiamondTrap enemy("enemy");
	
	hyeongki.attack("enemy");
	enemy.attack("hyeongki");
	hyeongki.whoAmI();
	enemy.whoAmI();
	return 0;
}
