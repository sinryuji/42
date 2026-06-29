/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:12:47 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/21 19:48:02 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include <unistd.h>

static int	print_num_sign(t_flag *flag, char *str)
{
	int	ret;

	ret = 0;
	if (flag->num_minus)
		ret += write(1, "-", 1);
	else if (flag->pointer)
		ret += write(1, "0x", 2);
	else if (flag->hash && *str != '0')
	{
		if (flag->hexa == 'x')
			ret += write(1, "0x", 2);
		if (flag->hexa == 'X')
			ret += write(1, "0X", 2);
	}
	else if (flag->space)
		ret += write(1, " ", 1);
	else if (flag->plus)
		ret += write(1, "+", 1);
	return (ret);
}

static int	print_num(char *str, t_flag *flag)
{
	int	ret;
	int	strlen;
	int	gap;

	ret = 0;
	strlen = ft_strlen(str);
	gap = flag->width - ft_max(strlen, flag->precision);
	if (!flag->minus && (!flag->zero || (flag->zero && flag->pre_flag)))
		while (gap-- > 0)
				ret += write(1, " ", 1);
	ret += print_num_sign(flag, str);
	if (flag->precision > 0)
		while (flag->precision-- > strlen)
			ret += write(1, "0", 1);
	if (flag->zero)
		while (gap-- > 0)
			ret += write(1, "0", 1);
	ret += write(1, str, strlen);
	while (gap-- > 0)
		ret += write(1, " ", 1);
	free(str);
	return (ret);
}

int	convert_str(t_flag *flag, long long n)
{
	char	*str;
	int		i;

	i = 0;
	if (flag->pre_flag && !flag->precision && !n)
		str = ft_strdup("");
	else
	{
		if (flag->pointer)
			str = ft_ultoa_base(n, flag->num_base);
		else
			str = ft_itoa_base(n, flag->num_base);
		if (flag->hexa == 'X')
		{
			while (str[i])
			{
				str[i] = ft_toupper(str[i]);
				i++;
			}
		}
	}
	return (print_num(str, flag));
}
