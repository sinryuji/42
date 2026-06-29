/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:48:11 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 14:50:52 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ascending_triangle_a_3(t_stack **a, t_stack **b)
{
	int	arr[3];

	arr[0] = (*a)->data;
	arr[1] = (*a)->next->data;
	arr[2] = (*a)->next->next->data;
	if (arr[0] < arr[2] && arr[2] < arr[1])
		return (ra(a) && sa(a) && ra(a) && ra(a));
	if (arr[1] < arr[0] && arr[0] < arr[2])
		return (sa(a) && ra(a) && ra(a) && ra(a));
	if (arr[2] < arr[0] && arr[0] < arr[1])
		return (pb(a, b) && sa(a) && ra(a) && pa(a, b) && ra(a) && ra(a));
	if (arr[2] < arr[1] && arr[1] < arr[0])
		return (pb(a, b) && sa(a) && ra(a) && ra(a) && pa(a, b) && ra(a));
	if (arr[1] < arr[2] && arr[2] < arr[0])
		return (pb(a, b) && ra(a) && ra(a) && pa(a, b) && ra(a));
	return (ra(a) && ra(a) && ra(a));
}

int	descending_triangle_a_3(t_stack **a, t_stack **b)
{
	int	arr[3];

	arr[0] = (*a)->data;
	arr[1] = (*a)->next->data;
	arr[2] = (*a)->next->next->data;
	if (arr[0] < arr[1] && arr[1] < arr[2])
		return (pb(a, b) && sa(a) && ra(a) && ra(a) && pa(a, b) && ra(a));
	if (arr[0] < arr[2] && arr[2] < arr[1])
		return (pb(a, b) && ra(a) && ra(a) && pa(a, b) && ra(a));
	if (arr[1] < arr[0] && arr[0] < arr[2])
		return (pb(a, b) && sa(a) && ra(a) && pa(a, b) && ra(a) && ra(a));
	if (arr[2] < arr[0] && arr[0] < arr[1])
		return (sa(a) && ra(a) && ra(a) && ra(a));
	if (arr[1] < arr[2] && arr[2] < arr[0])
		return (ra(a) && sa(a) && ra(a) && ra(a));
	return (ra(a) && ra(a) && ra(a));
}

int	ascending_triangle_a_4(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*max;

	i = 1;
	max = *a;
	while (i < 4)
	{
		if (get_index_node(*a, i)->data > max->data)
			max = get_index_node(*a, i);
		i++;
	}
	i = 0;
	while (get_node_index(max, *a))
		i += ra(a);
	pb(a, b);
	while (i)
		i -= rra(a);
	ascending_triangle_a_3(a, b);
	pa(a, b);
	ra(a);
	return (1);
}

int	descending_triangle_a_4(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*min;

	i = 1;
	min = *a;
	while (i < 4)
	{
		if (get_index_node(*a, i)->data < min->data)
			min = get_index_node(*a, i);
		i++;
	}
	i = 0;
	while (get_node_index(min, *a))
		i += ra(a);
	pb(a, b);
	while (i)
		i -= rra(a);
	descending_triangle_a_3(a, b);
	pa(a, b);
	ra(a);
	return (1);
}

int	make_triangle_a(t_stack **a, t_stack **b, int size, int ascending)
{
	if (size == 1)
		return (ra(a));
	else if (size == 2)
	{
		if (((*a)->data > (*a)->next->data) == ascending)
			sa(a);
		return (ra(a) && ra(a));
	}
	else if (size == 3)
	{
		if (ascending)
			return (ascending_triangle_a_3(a, b));
		else
			return (descending_triangle_a_3(a, b));
	}
	else
	{
		if (ascending)
			return (ascending_triangle_a_4(a, b));
		else
			return (descending_triangle_a_4(a, b));
	}
}
