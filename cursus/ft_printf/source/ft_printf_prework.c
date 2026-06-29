/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prework.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:40:51 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/21 19:48:18 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../lib/libft/include/libft.h"

void	prework_flag(t_flag *flag, const char **format)
{
	while (**format == '-' || **format == '0' || **format == '#'
		|| **format == '+' || **format == ' ')
	{
		if (**format == '-')
			flag->minus = 1;
		else if (**format == '0')
			flag->zero = 1;
		else if (**format == '#')
			flag->hash = 1;
		else if (**format == '+')
			flag->plus = 1;
		else if (**format == ' ')
			flag->space = 1;
		(*format)++;
	}
	if (flag->minus && flag->zero)
		flag->zero = 0;
}

void	prework_width(t_flag *flag, const char **format)
{
	int	n;

	n = ft_atoi(*format);
	if (n < 0)
		flag->error = 1;
	flag->width = n;
	while (ft_isdigit(**format))
		(*format)++;
}

void	prework_precision(t_flag *flag, const char **format)
{
	int	n;

	if (**format == '.')
	{
		(*format)++;
		flag->pre_flag = 1;
		if (ft_isdigit(**format))
		{
			n = ft_atoi(*format);
			flag->precision = n;
			if (n < 0)
				flag->error = 1;
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
}
