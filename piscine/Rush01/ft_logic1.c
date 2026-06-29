/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:59:48 by jungchoi          #+#    #+#             */
/*   Updated: 2022/01/16 13:59:55 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	check_col_up(int tab[4][4], int arr[16], int pos)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
			i++;
		}
		if (arr[pos % 4] != count)
			return (0);
	}
	return (1);
}

int	check_col_down(int tab[4][4], int arr[16], int pos)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (0 <= i)
		{
			if (tab[i][pos % 4] > max)
			{
				max = tab[i][pos % 4];
				count++;
			}
			i--;
		}
		if (arr[4 + pos % 4] != count)
			return (0);
	}
	return (1);
}
