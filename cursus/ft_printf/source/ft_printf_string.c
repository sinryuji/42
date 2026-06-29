/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:39:46 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/21 19:48:29 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include <unistd.h>

static int	write_padding(int strlen, t_flag *flag)
{
	int		ret;
	char	c;

	ret = 0;
	if (flag->zero)
		c = '0';
	else
		c = ' ';
	while (flag->width-- > strlen)
		ret += write(1, &c, 1);
	return (ret);
}

int	ft_printf_char(va_list *ap, t_flag *flag)
{
	char	c;
	int		ret;

	c = va_arg(*ap, int);
	ret = 0;
	if (flag->minus)
	{
		ret += write(1, &c, 1);
		ret += write_padding(1, flag);
	}
	else
	{
		ret += write_padding(1, flag);
		ret += write(1, &c, 1);
	}
	return (ret);
}

int	ft_printf_percent(t_flag *flag)
{
	int	ret;

	ret = 0;
	if (flag->minus)
	{
		ret += write(1, "%", 1);
		ret += write_padding(1, flag);
	}
	else
	{
		ret += write_padding(1, flag);
		ret += write(1, "%", 1);
	}
	return (ret);
}

int	ft_printf_string(va_list *ap, t_flag *flag)
{
	char	*str;
	int		ret;	
	int		strlen;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = "(null)";
	ret = 0;
	strlen = ft_strlen(str);
	if (flag->precision < strlen && flag->pre_flag)
		strlen = flag->precision;
	if (flag->minus)
	{
		ret += write(1, str, strlen);
		ret += write_padding(strlen, flag);
	}
	else
	{
		ret += write_padding(strlen, flag);
		ret += write(1, str, strlen);
	}
	return (ret);
}
