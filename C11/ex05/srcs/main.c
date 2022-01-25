/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:02:20 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/25 21:42:13 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int main(int ac, char **av)
{
	int	x;
	int	y;
	int error_check;

	error_check = 0;
	if (ac == 4 && check_oper(av[2]))
	{
		x = ft_atoi(av[1]);
		y = ft_atoi(av[3]);
		if (*av[2] == '/' && y == 0)
		{
			ft_putstr("Stop : division by zero");
			return (0);
		}
		if (*av[2] == '%' && y == 0)
		{
			ft_putstr("Stop : modulo by zero");
			return (0);
		}
		error_check = cal_print(x, y, *av[2]);
	}
	if (!error_check)
	{
	    ft_putnbr(0);
	    write(1, "\n", 1);
	}
	return (0);
}
