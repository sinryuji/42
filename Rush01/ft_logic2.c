/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:00:03 by jungchoi          #+#    #+#             */
/*   Updated: 2022/01/16 14:00:06 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	check_row_left(int tab[4][4], int arr[16], int pos)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (tab[pos / 4][i] > max)
			{
				max = tab[pos / 4][i];
				count++;
			}
			i++;
		}
		if (arr[8 + pos / 4] != count)
			return (0);
	}
	return (1);
}

int	check_row_right(int tab[4][4], int arr[16], int pos)
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (pos % 4 == 3)
	{
		while (0 <= i)
		{
			if (tab[pos / 4][i] > max)
			{
				max = tab[pos / 4][i];
				count++;
			}
			i--;
		}
		if (arr[12 + pos / 4] != count)
			return (0);
	}
	return (1);
}
