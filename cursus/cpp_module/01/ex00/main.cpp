/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:21:58 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/22 19:33:43 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie z1("stack");
	Zombie* z2 = new Zombie("heap");
	randomChump("stack2");
	z1.announce();
	z2->announce();
	delete z2;
	return 0;
}
