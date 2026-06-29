/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:01:13 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/09 20:02:17 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(char c1, char c2, char c3)
{
	ft_putchar(c1);
	ft_putchar(c2);
	ft_putchar(c3);
	if (c1 <= '6')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = '0';
	c2 = '1';
	c3 = '2';
	while (c1 <= '7')
	{
		print(c1, c2, c3);
		c3++;
		if (c3 > '9')
		{
			c2++;
			c3 = c2 + 1;
		}
		if (c2 > '8')
		{
			c1++;
			c2 = c1 + 1;
			c3 = c2 + 1;
		}
	}
}
