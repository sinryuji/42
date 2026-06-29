/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:00:12 by jungchoi          #+#    #+#             */
/*   Updated: 2022/01/16 14:00:14 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	check_double(int tab[4][4], int count, int pos)
{
	int	i;

	i = 0;
	while (i < pos / 4)
	{
		if (tab[i][pos % 4] == count)
			return (0);
		i++;
	}
	i = 0;
	while (i < pos % 4)
	{
		if (tab[pos / 4][i] == count)
			return (0);
		i++;
	}
	return (1);
}

int	check_case(int tab[4][4], int arr[16], int pos)
{
	if (check_row_left(tab, arr, pos) == 0)
		return (0);
	if (check_row_right(tab, arr, pos) == 0)
		return (0);
	if (check_col_down(tab, arr, pos) == 0)
		return (0);
	if (check_col_up(tab, arr, pos) == 0)
		return (0);
	return (1);
}
