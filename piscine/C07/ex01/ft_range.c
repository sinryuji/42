/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:18:54 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/20 15:39:38 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}
