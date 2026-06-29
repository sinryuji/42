/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:29:05 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 21:06:08 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../lib/ft_printf/lib/libft/include/libft.h"

void	division(t_stack **a, t_stack **b, t_info info)
{
	int	i;

	if (info.depth % 2 == 0)
	{
		i = 0;
		while (i < info.pow)
		{
			make_triangle_a(a, b, get_size(info.pow, info.pow - 1 - i, info.n), \
			get_ascending(info.pow, i));
			i++;
		}
	}
	else
	{
		i = info.pow;
		while (i--)
			make_triangle_b(a, b, get_size(info.pow, info.pow - 1 - i, info.n), \
			get_ascending(info.pow, i));
	}
}

void	merge_sort(t_stack **a, t_stack **b)
{
	t_info	info;

	info.n = get_list_length(*a);
	if (info.n <= 5)
		small_case(a, b, info.n);
	else
	{
		info.depth = get_depth(info.n);
		info.pow = ft_pow(3, info.depth);
		division(a, b, info);
		merge(a, b, info);
	}
}
