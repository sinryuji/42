/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:42:02 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 16:06:45 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

static int	swap_stack(t_stack **top)
{
	int	data;
	int	data2;

	if (!*top || !(*top)->next)
		return (0);
	data = pop(top);
	data2 = pop(top);
	push(top, data);
	push(top, data2);
	return (1);
}

int	sa(t_stack **a)
{
	if (swap_stack(a))
		return (1);
	return (0);
}

int	sb(t_stack **b)
{
	if (swap_stack(b))
		return (1);
	return (0);
}

int	ss(t_stack **a, t_stack **b)
{
	if (swap_stack(a) && swap_stack(b))
		return (1);
	return (0);
}
