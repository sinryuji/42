/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:18:54 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/20 15:39:51 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = malloc(sizeof(int) * (max - min));
	if (!arr)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	*range = arr;
	return (max - min);
}
