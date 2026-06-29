/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:48:55 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/17 19:35:22 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	m_cnt;
	int	result;

	m_cnt = 0;
	result = 0;
	while (*str <= 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			m_cnt++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (m_cnt % 2 == 1)
		result *= -1;
	return (result);
}
