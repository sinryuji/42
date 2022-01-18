/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:00:23 by jungchoi          #+#    #+#             */
/*   Updated: 2022/01/16 14:00:25 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdlib.h>

int	ft_solve(int tab[4][4], int arr[16], int pos)
{
	int	count;

	if (pos == 16)
		return (1);
	count = 1;
	while (count <= 4)
	{
		if (check_double(tab, count, pos) == 1)
		{
			tab[pos / 4][pos % 4] = count;
			if (check_case(tab, arr, pos) == 1)
			{
				if (ft_solve(tab, arr, pos + 1) == 1)
					return (1);
			}
			else
				tab[pos / 4][pos % 4] = 0;
		}
		count++;
	}
	return (0);
}

void	ft_show(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(tab[i][j]);
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	tab[4][4];
	int	*arr;

	tab = (int *)malloc(4 * 4);
	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	arr = ft_av_atoi(av[1]);
	if (ft_check(arr, av[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ft_solve(tab, arr, 0) == 1)
		ft_show(tab);
	else
		ft_putstr("Error\n");
	free(arr);
	return (0);
}
