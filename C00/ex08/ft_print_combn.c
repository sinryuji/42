/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:25:40 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/10 11:44:44 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	change(int arr[], int n, int i)
{
	arr[n - i]++;
	if (i > n)
		return ;
	while (i > 1)
	{
		arr[n - i + 1] = arr[n - i] + 1;
		i--;
	}
}

void	check(int arr[], int n, int i, int max)
{
	if (arr[n - i] == max)
	{
		return (check(arr, n, i + 1, max - 1));
	}
	else
	{
		change(arr, n, i);
	}
}

void	print(int arr[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
	if (arr[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	i--;
	while (arr[0] <= 10 - n)
	{
		if (arr[i] <= 9)
		{
			print(arr, n);
			arr[n - 1]++;
		}
		else
		{
			arr[n - 1]--;
			check(arr, n, 1, 9);
		}
	}
}
