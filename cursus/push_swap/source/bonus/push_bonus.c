/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:52:44 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 16:05:42 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"

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
		return (1);
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	if (push_stack(b, a))
		return (1);
	return (0);
}
