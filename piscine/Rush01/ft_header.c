/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:03:02 by min-cho           #+#    #+#             */
/*   Updated: 2022/01/16 13:09:29 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ftprint(int n)
{
	int		i;
	int		g_i;
	char	g_arr[10];

	i = 0;
	g_i = 9;
	while (g_arr[i] < 10)
	{
		g_arr[i] = '\0';
		i++;
	}
	while (n > 0)
	{
		g_arr[g_i] = (n % 10 + '0');
		n /= 10;
		g_i--;
	}
	while (g_i < 10)
	{
		if (g_arr[g_i] != '\0')
			ft_putchar(g_arr[g_i]);
		g_i++;
	}
}

void	ft_putnbr(int nb)
{
	ftprint(nb);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
