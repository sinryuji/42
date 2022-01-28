/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:35:17 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/26 20:01:57 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

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

int	check_oper(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	if (len != 1)
		return (0);
	if (str[0] == '+')
		return (1);
	if (str[0] == '-')
		return (1);
	if (str[0] == '/')
		return (1);
	if (str[0] == '%')
		return (1);
	if (str[0] == '*')
		return (1);
	return (0);
}

void	cal_print(int x, int y, char oper, int (*fp[])(int, int))
{
	if (oper == '+')
		ft_putnbr(fp[0](x, y));
	if (oper == '-')
		ft_putnbr(fp[1](x, y));
	if (oper == '/')
		ft_putnbr(fp[3](x, y));
	if (oper == '%')
		ft_putnbr(fp[4](x, y));
	if (oper == '*')
		ft_putnbr(fp[2](x, y));
	write(1, "\n", 1);
}

int	check_error(char c, int	y)
{
	if (c == '/' && y == 0)
	{
		ft_putstr("Stop : division by zero");
		return (1);
	}
	if (c == '%' && y == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return (1);
	}
	return (0);
}
