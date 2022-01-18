/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:47:54 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/09 20:05:16 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		ft_putchar('0');
		ft_putchar(c);
	}
	else
	{
		c = n / 10 + '0';
		ft_putchar(c);
		c = n % 10 + '0';
		ft_putchar(c);
	}
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	n2 = 1;
	while (n1 <= 98)
	{
		while (n2 <= 99)
		{
			print(n1);
			ft_putchar(' ');
			print(n2);
			if (n1 < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			n2++;
		}
		n1++;
		n2 = n1 + 1;
	}
}
