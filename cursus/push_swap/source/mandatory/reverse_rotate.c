/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:56:45 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/10 14:08:20 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../lib/ft_printf/include/ft_printf.h"
#include <stdlib.h>

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
	{
		ft_printf("rra\n");
		return (1);
	}
	return (0);
}

int	rrb(t_stack **b)
{
	if (reverse_rotate_stack(b))
	{
		ft_printf("rrb\n");
		return (1);
	}
	return (0);
}

int	rrr(t_stack **a, t_stack **b)
{
	if (reverse_rotate_stack(a) && reverse_rotate_stack(b))
	{
		ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
