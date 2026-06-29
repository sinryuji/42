/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:31:59 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 21:05:43 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_depth(int n)
{
	int	depth;

	depth = 0;
	while (n > 4)
	{
		n = n / 3 + (n % 3 > 0);
		depth++;
	}
	return (depth);
}

int	get_ascending(int pow, int i)
{
	int	ret;

	ret = 1;
	while (pow > 1)
	{
		if (i < pow * 2 / 3)
		{
			i = (pow / 3 - 1) - (i % (pow / 3));
			ret = !ret;
		}
		else
			i = i - pow * 2 / 3;
		pow /= 3;
	}
	return (ret);
}

t_info	get_root(int x, int pow, int range, t_info info)
{
	while (pow > 3)
	{
		if (x <= range)
			range -= pow / 9 * 2;
		else if (x <= range + pow / 3)
		{
			if (info.cnt % 2 == 0)
				info.root += pow / 3;
			else
				info.root -= pow / 3;
			range += pow / 3 / 3;
		}
		else
		{
			if (info.cnt % 2 == 0)
				info.root -= pow / 3;
			else
				info.root += pow / 3;
			range += pow / 3 + pow / 3 / 3;
			info.cnt++;
		}
		pow /= 3;
		info.cnt++;
	}
	return (info);
}

int	get_y(int x, int pow)
{
	t_info	info;

	info.cnt = 0;
	info.root = (pow - 1) / 2;
	info = get_root(x, pow, pow / 3, info);
	if (info.cnt % 2 == 0)
	{
		if (x % 3 == 2)
			info.root++;
		else if (x % 3 == 0)
			info.root--;
	}
	else
	{
		if (x % 3 == 2)
			info.root--;
		else if (x % 3 == 0)
			info.root++;
	}
	return (info.root);
}

int	get_size(int pow, int i, int n)
{
	int	x;
	int	y;
	int	ret;

	x = n % pow;
	ret = n / pow;
	while (x)
	{
		y = get_y(x, pow);
		if (i == y)
			return (ret + 1);
		x--;
	}
	return (ret);
}
