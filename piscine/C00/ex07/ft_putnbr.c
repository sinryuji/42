/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:05:24 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/09 20:07:52 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int arr[], int nb, int i)
{
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		else
			ft_putchar('-');
	}
	while (i >= 0)
	{
		ft_putchar(arr[i] + '0');
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int	arr[10];
	int	i;
	int	n;

	i = 0;
	if (nb < 0)
		n = nb * -1;
	else
		n = nb;
	while (n != 0)
	{
		arr[i] = n % 10;
		n /= 10;
		i++;
	}
	i--;
	print (arr, nb, i);
}
