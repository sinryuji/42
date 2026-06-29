/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:59:18 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/21 19:47:23 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include <unistd.h>

static int	select_specifier(char spec, va_list *ap, t_flag *flag)
{
	int	ret;

	ret = 0;
	if (spec == 'c')
		ret = ft_printf_char(ap, flag);
	else if (spec == 's')
		ret = ft_printf_string(ap, flag);
	else if (spec == 'p')
		ret = ft_printf_pointer(ap, flag);
	else if (spec == 'd' || spec == 'i')
		ret = ft_printf_decimal(ap, flag);
	else if (spec == 'u')
		ret = ft_printf_unsigned(ap, flag);
	else if (spec == 'x' || spec == 'X')
		ret = ft_printf_hexa(ap, spec, flag);
	else if (spec == '%')
		ret = ft_printf_percent(flag);
	else
		flag->error = 1;
	return (ret);
}

static int	ft_printf_processing(const char *format, va_list ap, t_flag *flag)
{
	int	ret;

	ret = 0;
	while (*format)
	{
		ft_memset(flag, 0, sizeof(t_flag));
		if (*format == '%')
		{
			format++;
			prework_flag(flag, &format);
			prework_width(flag, &format);
			prework_precision(flag, &format);
			ret += select_specifier(*format, &ap, flag);
		}
		else
			ret += write(1, format, 1);
		format++;
		if (flag->error)
		{
			ret = -1;
			break ;
		}
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	t_flag	*flag;

	va_start(ap, format);
	flag = malloc(sizeof(t_flag));
	ret = ft_printf_processing(format, ap, flag);
	va_end(ap);
	free(flag);
	return (ret);
}
