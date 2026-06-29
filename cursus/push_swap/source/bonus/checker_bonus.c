/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:59:51 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 16:45:53 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker_bonus.h"
#include "../../lib/ft_printf/include/ft_printf.h"
#include "../../lib/ft_printf/lib/libft/include/libft.h"
#include <stdlib.h>
#include <unistd.h>

int	check_sort(t_stack *top)
{
	while (top && top->next)
	{
		if (top->data > top->next->data)
			return (0);
		top = top->next;
	}	
	return (1);
}

static void	operator(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp(op, "sa\n", ft_strlen(op)) == 0)
		sa(a);
	else if (ft_strncmp(op, "sb\n", ft_strlen(op)) == 0)
		sb(b);
	else if (ft_strncmp(op, "ss\n", ft_strlen(op)) == 0)
		ss(a, b);
	else if (ft_strncmp(op, "pa\n", ft_strlen(op)) == 0)
		pa(a, b);
	else if (ft_strncmp(op, "pb\n", ft_strlen(op)) == 0)
		pb(a, b);
	else if (ft_strncmp(op, "ra\n", ft_strlen(op)) == 0)
		ra(a);
	else if (ft_strncmp(op, "rb\n", ft_strlen(op)) == 0)
		rb(b);
	else if (ft_strncmp(op, "rr\n", ft_strlen(op)) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rra\n", ft_strlen(op)) == 0)
		rra(a);
	else if (ft_strncmp(op, "rrb\n", ft_strlen(op)) == 0)
		rrb(b);
	else if (ft_strncmp(op, "rrr\n", ft_strlen(op)) == 0)
		rrr(a, b);
	else
		ft_puterr("Error\n");
}

static void	operator_apply(t_stack **a, t_stack **b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		operator(a, b, op);
		free(op);
	}
}

void	print_state(t_stack *a, t_stack *b)
{
	ft_printf("a : ");
	print_stack(a);
	ft_printf("b : ");
	print_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	integer_validation(argc, argv);
	init_stack(&a, argc, argv);
	duplication_validation(a);
	operator_apply(&a, &b);
	if (check_sort(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	while (a)
		pop(&a);
	return (0);
}
