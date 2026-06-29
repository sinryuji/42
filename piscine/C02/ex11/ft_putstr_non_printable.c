/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:45:37 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/14 19:35:52 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char			*hex;
	int				i;
	unsigned char	c;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i] != '\0')
	{
		c = str[i];
		if (c >= 32 && c <= 126)
			ft_putchar(c);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex[c / 16]);
			ft_putchar(hex[c % 16]);
		}
		i++;
	}
}
