/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:01:31 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/06 18:42:58 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct s_flag
{
	int		width;
	int		minus;
	int		zero;
	int		precision;
	int		num_base;
	int		num_minus;
	char	hexa;
	int		pointer;
	int		pre_flag;
	int		hash;
	int		space;
	int		plus;
	int		error;
}	t_flag;

/* ft_printf.c */
int		ft_printf(const char *format, ...);

/* ft_printf_string.c */
int		ft_printf_string(va_list ap, t_flag *flag);
int		ft_printf_char(va_list ap, t_flag *flag);
int		ft_printf_percent(t_flag *flag);

/* ft_printf_num.c */
int		ft_printf_decimal(va_list ap, t_flag *flag);
int		ft_printf_unsigned(va_list ap, t_flag *flag);
int		ft_printf_hexa(va_list ap, char spec, t_flag *flag);
int		ft_printf_pointer(va_list ap, t_flag *flag);

/* ft_printf_num2.c */
int		convert_str(t_flag *flag, long long n);

/* ft_printf_prework.c */
void	prework_flag(t_flag *flag, const char **format);
void	prework_width(t_flag *flag, const char **format);
void	prework_precision(t_flag *flag, const char **format);

#endif
