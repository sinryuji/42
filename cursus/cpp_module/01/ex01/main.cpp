/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:50:38 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/22 19:56:07 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	zombies;
	const int	n = 10;

	zombies = zombieHorde(n, "zombie");
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete [] zombies;
	return 0;
}
