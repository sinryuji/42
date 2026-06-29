/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:06:42 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 14:50:28 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	size_4(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*min;

	i = 0;
	min = *a;
	while (++i < 4)
	{
		if (get_index_node(*a, i)->data < min->data)
			min = get_index_node(*a, i);
	}
	if (get_node_index(min, *a) == 0)
		return (pb(a, b) && small_case(a, b, 3) && pa(a, b));
	else if (get_node_index(min, *a) == 1)
		return (ra(a) && pb(a, b) && small_case(a, b, 3) && pa(a, b));
	else if (get_node_index(min, *a) == 2)
		return (ra(a) && ra(a) && pb(a, b) && small_case(a, b, 3) && pa(a, b));
	else
		return (rra(a) && pb(a, b) && small_case(a, b, 3) && pa(a, b));
}

int	size_5(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*min;

	i = 0;
	min = *a;
	while (++i < 5)
	{
		if (get_index_node(*a, i)->data < min->data)
			min = get_index_node(*a, i);
	}
	if (get_node_index(min, *a) == 0)
		return (pb(a, b) && small_case(a, b, 4) && pa(a, b));
	else if (get_node_index(min, *a) == 1)
		return (ra(a) && pb(a, b) && small_case(a, b, 4) && pa(a, b));
	else if (get_node_index(min, *a) == 2)
		return (ra(a) && ra(a) && pb(a, b) && small_case(a, b, 4) && pa(a, b));
	else if (get_node_index(min, *a) == 3)
		return (rra(a) && rra(a) && pb(a, b) && \
		small_case(a, b, 4) && pa(a, b));
	else
		return (rra(a) && pb(a, b) && small_case(a, b, 4) && pa(a, b));
}

int	small_case(t_stack **a, t_stack **b, int n)
{
	if (n == 2 && (*a)->data > (*a)->next->data)
		sa(a);
	if (n == 3)
	{
		if ((*a)->data > (*a)->next->data && \
			(*a)->data > (*a)->next->next->data)
			ra(a);
		else if ((*a)->next->data > (*a)->data && \
			(*a)->next->data > (*a)->next->next->data)
			rra(a);
		if ((*a)->data > (*a)->next->data)
			sa(a);
	}
	else if (n == 4)
		size_4(a, b);
	else if (n == 5)
		size_5(a, b);
	return (1);
}
