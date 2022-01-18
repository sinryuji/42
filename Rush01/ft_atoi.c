/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:57:47 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/16 13:07:13 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_av_atoi(char *av)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * 16);
	while (*av)
	{
		if (*av != ' ' && *av != '\n')
		{
			arr[i] = *av - '0';
			i++;
		}
		av++;
	}
	return (arr);
}

int	ft_check(int arr[], char str[])
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4'
			&& str[i + 1] >= '1' && str[i + 1] <= '4')
			return (1);
		i++;
	}
	i = 0;
	while (arr[i])
		i++;
	if (i != 16)
		return (1);
	return (0);
}
