/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:52:44 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 14:50:05 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../lib/ft_printf/include/ft_printf.h"

static int	push_stack(t_stack **to, t_stack **from)
{
	if (!*from)
		return (0);
	push(to, pop(from));
	return (1);
}

int	pa(t_stack **a, t_stack **b)
{
	if (push_stack(a, b))
	{
		ft_printf("pa\n");
		return (1);
	}
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	if (push_stack(b, a))
	{
		ft_printf("pb\n");
		return (1);
	}
	return (0);
}
