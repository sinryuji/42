/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:28:27 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 14:50:31 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	merge_ascending_a_to_b(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_top;
	int	a_bot;
	int	b_bot;

	a_top = get_size(info.pow, info.pow / 3 + i, info.n);
	a_bot = get_size(info.pow, info.pow / 3 - 1 - i, info.n);
	b_bot = get_size(info.pow, info.pow * 2 / 3 + i, info.n);
	while (a_top + a_bot + b_bot)
	{
		if (a_top && (!a_bot || (*a)->data > get_last_node(*a)->data)
			&& (!b_bot || (*a)->data > get_last_node(*b)->data))
			a_top -= pb(a, b);
		else if (a_bot && (!a_top || get_last_node(*a)->data > (*a)->data)
			&& (!b_bot || get_last_node(*a)->data > get_last_node(*b)->data))
		{
			rra(a);
			a_bot -= pb(a, b);
		}
		else if (b_bot && (!a_top || get_last_node(*b)->data > (*a)->data)
			&& (!a_bot || get_last_node(*b)->data > get_last_node(*a)->data))
			b_bot -= rrb(b);
	}
}

void	merge_descending_a_to_b(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_top;
	int	a_bot;
	int	b_bot;

	a_top = get_size(info.pow, info.pow / 3 + i, info.n);
	a_bot = get_size(info.pow, info.pow / 3 - 1 - i, info.n);
	b_bot = get_size(info.pow, info.pow * 2 / 3 + i, info.n);
	while (a_top + a_bot + b_bot)
	{
		if (a_top && (!a_bot || (*a)->data < get_last_node(*a)->data)
			&& (!b_bot || (*a)->data < get_last_node(*b)->data))
			a_top -= pb(a, b);
		else if (a_bot && (!a_top || get_last_node(*a)->data < (*a)->data)
			&& (!b_bot || get_last_node(*a)->data < get_last_node(*b)->data))
		{
			rra(a);
			a_bot -= pb(a, b);
		}
		else if (b_bot && (!a_top || get_last_node(*b)->data < (*a)->data)
			&& (!a_bot || get_last_node(*b)->data < get_last_node(*a)->data))
			b_bot -= rrb(b);
	}
}

void	merge_ascending_b_to_a(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_bot;
	int	b_top;
	int	b_bot;

	b_top = get_size(info.pow, info.pow / 3 + i, info.n);
	b_bot = get_size(info.pow, info.pow / 3 - 1 - i, info.n);
	a_bot = get_size(info.pow, info.pow * 2 / 3 + i, info.n);
	while (a_bot + b_top + b_bot)
	{
		if (b_top && (!b_bot || (*b)->data > get_last_node(*b)->data)
			&& (!a_bot || (*b)->data > get_last_node(*a)->data))
			b_top -= pa(a, b);
		else if (b_bot && (!b_top || get_last_node(*b)->data > (*b)->data)
			&& (!a_bot || get_last_node(*b)->data > get_last_node(*a)->data))
		{
			rrb(b);
			b_bot -= pa(a, b);
		}
		else if (a_bot && (!b_top || get_last_node(*a)->data > (*b)->data)
			&& (!b_bot || get_last_node(*a)->data > get_last_node(*b)->data))
			a_bot -= rra(a);
	}
}

void	merge_descending_b_to_a(t_stack **a, t_stack **b, t_info info, int i)
{
	int	a_bot;
	int	b_top;
	int	b_bot;

	b_top = get_size(info.pow, info.pow / 3 + i, info.n);
	b_bot = get_size(info.pow, info.pow / 3 - 1 - i, info.n);
	a_bot = get_size(info.pow, info.pow * 2 / 3 + i, info.n);
	while (a_bot + b_top + b_bot)
	{
		if (b_top && (!b_bot || (*b)->data < get_last_node(*b)->data)
			&& (!a_bot || (*b)->data < get_last_node(*a)->data))
			b_top -= pa(a, b);
		else if (b_bot && (!b_top || get_last_node(*b)->data < (*b)->data)
			&& (!a_bot || get_last_node(*b)->data < get_last_node(*a)->data))
		{
			rrb(b);
			b_bot -= pa(a, b);
		}
		else if (a_bot && (!b_top || get_last_node(*a)->data < (*b)->data)
			&& (!b_bot || get_last_node(*a)->data < get_last_node(*b)->data))
			a_bot -= rra(a);
	}
}
