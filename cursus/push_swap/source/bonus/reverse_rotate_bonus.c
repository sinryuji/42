/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:56:45 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/10 14:08:48 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"
#include <stdlib.h>

t_stack	*get_last_node(t_stack *top)
{
	while (top->next)
		top = top->next;
	return (top);
}

static int	reverse_rotate_stack(t_stack **top)
{
	t_stack	*last;

	if (!*top || !(*top)->next)
		return (0);
	last = get_last_node(*top);
	last->next = *top;
	(*top)->prev = last;
	*top = last;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
	return (1);
}

int	rra(t_stack **a)
{
	if (reverse_rotate_stack(a))
		return (1);
	return (0);
}

int	rrb(t_stack **b)
{
	if (reverse_rotate_stack(b))
		return (1);
	return (0);
}

int	rrr(t_stack **a, t_stack **b)
{
	if (reverse_rotate_stack(a) && reverse_rotate_stack(b))
		return (1);
	return (0);
}
