/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:27:33 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 14:49:45 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	merge_a_to_b(t_stack **a, t_stack **b, t_info info, int size)
{
	int	i;

	while (size--)
		pb(a, b);
	i = info.pow / 3;
	while (i--)
	{
		if (get_ascending(info.pow / 3, i))
			merge_ascending_a_to_b(a, b, info, i);
		else
			merge_descending_a_to_b(a, b, info, i);
	}
}

void	merge_b_to_a(t_stack **a, t_stack **b, t_info info, int size)
{
	int	i;

	while (size--)
		pa(a, b);
	i = info.pow / 3;
	while (i--)
	{
		if (get_ascending(info.pow / 3, i))
			merge_ascending_b_to_a(a, b, info, i);
		else
			merge_descending_b_to_a(a, b, info, i);
	}
}

void	merge(t_stack **a, t_stack **b, t_info info)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (i < info.pow / 3)
		size += get_size(info.pow, info.pow * 2 / 3 + i++, info.n);
	if (info.depth % 2 == 0)
		merge_a_to_b(a, b, info, size);
	else
		merge_b_to_a(a, b, info, size);
	if (info.depth > 1)
	{
		info.depth--;
		info.pow /= 3;
		merge(a, b, info);
	}
}
