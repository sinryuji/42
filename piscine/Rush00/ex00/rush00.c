/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobae <mobae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:20:46 by mobae             #+#    #+#             */
/*   Updated: 2022/01/09 16:20:48 by mobae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_put_row(char lt, char mid, char rt, int col_cnt)
{
	if (col_cnt == 1)
		ft_putchar(lt);
	else if (col_cnt == 2)
	{
		ft_putchar(lt);
		ft_putchar(rt);
	}
	else
	{
		ft_putchar(lt);
		col_cnt = col_cnt - 1;
		while (col_cnt != 1)
		{
			ft_putchar(mid);
			col_cnt = col_cnt - 1;
		}
		ft_putchar(rt);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
	{
		return ;
	}
	i = 0;
	while (i < y)
	{
		if (i == 0)
		{
			ft_put_row('o', '-', 'o', x);
		}
		else if (i == y - 1)
		{
			ft_put_row('o', '-', 'o', x);
		}
		else
		{
			ft_put_row('|', ' ', '|', x);
		}
		i++;
	}
}
