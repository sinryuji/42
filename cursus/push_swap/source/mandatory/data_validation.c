/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:50:28 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 14:47:50 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../lib/ft_printf/lib/libft/include/libft.h"
#include <limits.h>

int	split_check(char **split)
{
	int		i;
	long	n;
	char	*str;

	i = 0;
	while (split[i])
	{
		str = split[i++];
		n = ft_atol(str);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		if (n < 0)
			str++;
		while (*str)
		{
			if (!(ft_isdigit(*str) || *str == ' '))
				return (0);
			str++;
		}
	}
	return (1);
}

void	integer_validation(int argc, char **argv)
{
	int		i;
	char	**split;

	if (argc == 1)
		exit(0);
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		if (!split[0] || !split_check(split))
		{
			ft_split_free(split);
			ft_puterr("Error\n");
		}
		ft_split_free(split);
	}
}

void	duplication_validation(t_stack *top)
{
	t_stack	*current;
	t_stack	*tmp;

	while (top)
	{
		current = top;
		tmp = top->next;
		while (tmp)
		{
			if (current->data == tmp->data)
				ft_puterr("Error\n");
			tmp = tmp->next;
		}
		top = top->next;
	}
}
