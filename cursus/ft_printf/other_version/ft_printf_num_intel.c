/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_intel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:12:41 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/21 19:55:16 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_decimal(va_list ap, t_flag *flag)
{
	long	n;

	n = va_arg(ap, int);
	flag->num_base = 10;
	if (n < 0)
	{
		flag->num_minus = 1;
		n *= -1;
		flag->width--;
	}
	return (convert_str(flag, n));
}

int	ft_printf_unsigned(va_list ap, t_flag *flag)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	flag->num_base = 10;
	return (convert_str(flag, n));
}

int	ft_printf_hexa(va_list ap, char spec, t_flag *flag)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	flag->num_base = 16;
	flag->hexa = spec;
	return (convert_str(flag, n));
}

int	ft_printf_pointer(va_list ap, t_flag *flag)
{
	unsigned long	n;

	n = (unsigned long)va_arg(ap, void *);
	flag->num_base = 16;
	flag->pointer = 1;
	flag->width -= 2;
	return (convert_str(flag, n));
}
