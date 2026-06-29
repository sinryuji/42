/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:02:20 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/26 20:14:29 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int ac, char **av)
{
	int	x;
	int	y;
	int	(*fp[5])(int, int);

	if (ac != 4)
		return (0);
	if (check_oper(av[2]))
	{
		x = ft_atoi(av[1]);
		y = ft_atoi(av[3]);
		if (check_error(*av[2], y))
			return (0);
		fp[0] = cal_add;
		fp[1] = cal_min;
		fp[2] = cal_mul;
		fp[3] = cal_div;
		fp[4] = cal_mod;
		cal_print(x, y, *av[2], fp);
		return (0);
	}
	ft_putnbr(0);
	write(1, "\n", 1);
}
