/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:48:11 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 14:50:56 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ascending_triangle_b_3(t_stack **a, t_stack **b)
{
	int	arr[3];

	arr[0] = (*a)->data;
	arr[1] = (*a)->next->data;
	arr[2] = (*a)->next->next->data;
	if (arr[0] < arr[1] && arr[1] < arr[2])
		return (pb(a, b) && sa(a) && pb(a, b) && sb(b) && pb(a, b) && sb(b));
	if (arr[0] < arr[2] && arr[2] < arr[1])
		return (sa(a) && pb(a, b) && sa(a) && pb(a, b) && pb(a, b));
	if (arr[1] < arr[0] && arr[0] < arr[2])
		return (pb(a, b) && sa(a) && pb(a, b) && sb(b) && pb(a, b));
	if (arr[2] < arr[0] && arr[0] < arr[1])
		return (sa(a) && pb(a, b) && pb(a, b) && pb(a, b));
	if (arr[1] < arr[2] && arr[2] < arr[0])
		return (pb(a, b) && sa(a) && pb(a, b) && pb(a, b));
	return (pb(a, b) && pb(a, b) && pb(a, b));
}

int	descending_triangle_b_3(t_stack **a, t_stack **b)
{
	int	arr[3];

	arr[0] = (*a)->data;
	arr[1] = (*a)->next->data;
	arr[2] = (*a)->next->next->data;
	if (arr[0] < arr[2] && arr[2] < arr[1])
		return (pb(a, b) && sa(a) && pb(a, b) && pb(a, b));
	if (arr[1] < arr[0] && arr[0] < arr[2])
		return (sa(a) && pb(a, b) && pb(a, b) && pb(a, b));
	if (arr[2] < arr[0] && arr[0] < arr[1])
		return (pb(a, b) && sa(a) && pb(a, b) && sb(b) && pb(a, b));
	if (arr[2] < arr[1] && arr[1] < arr[0])
		return (pb(a, b) && sa(a) && pb(a, b) && sb(b) && pb(a, b) && sb(b));
	if (arr[1] < arr[2] && arr[2] < arr[0])
		return (sa(a) && pb(a, b) && sa(a) && pb(a, b) && pb(a, b));
	return (pb(a, b) && pb(a, b) && pb(a, b));
}

int	ascending_triangle_b_4(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*max;

	i = 1;
	max = *a;
	while (i < 3)
	{
		if (get_index_node(*a, i)->data > max->data)
			max = get_index_node(*a, i);
		i++;
	}
	if (get_last_node(*a)->data > max->data)
		max = get_last_node(*a);
	if (get_node_index(max, *a) == 0)
		return (pb(a, b) && rra(a) && ascending_triangle_b_3(a, b));
	else if (get_node_index(max, *a) == 1)
		return (sa(a) && pb(a, b) && rra(a) && ascending_triangle_b_3(a, b));
	else if (get_node_index(max, *a) == 2)
		return (ra(a) && sa(a) && pb(a, b) && rra(a) && rra(a) \
		&& ascending_triangle_b_3(a, b));
	else
		return (rra(a) && pb(a, b) && ascending_triangle_b_3(a, b));
}

int	descending_triangle_b_4(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*min;

	i = 1;
	min = *a;
	while (i < 3)
	{
		if (get_index_node(*a, i)->data < min->data)
			min = get_index_node(*a, i);
		i++;
	}
	if (get_last_node(*a)->data < min->data)
		min = get_last_node(*a);
	if (get_node_index(min, *a) == 0)
		return (pb(a, b) && rra(a) && descending_triangle_b_3(a, b));
	else if (get_node_index(min, *a) == 1)
		return (sa(a) && pb(a, b) && rra(a) && descending_triangle_b_3(a, b));
	else if (get_node_index(min, *a) == 2)
		return (ra(a) && sa(a) && pb(a, b) && rra(a) && rra(a) \
		&& descending_triangle_b_3(a, b));
	else
		return (rra(a) && pb(a, b) && descending_triangle_b_3(a, b));
}

int	make_triangle_b(t_stack **a, t_stack **b, int size, int ascending)
{
	if (size == 1)
		return (pb(a, b));
	else if (size == 2)
	{
		if (((*a)->data > (*a)->next->data) != ascending)
			sa(a);
		return (pb(a, b) && pb(a, b));
	}
	else if (size == 3)
	{
		if (ascending)
			return (ascending_triangle_b_3(a, b));
		else
			return (descending_triangle_b_3(a, b));
	}
	else
	{
		if (ascending)
			return (ascending_triangle_b_4(a, b));
		else
			return (descending_triangle_b_4(a, b));
	}
}
