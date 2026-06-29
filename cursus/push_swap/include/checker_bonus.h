/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:56:53 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 20:11:04 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

typedef struct s_stack
{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/* data_validation_bonus.c */
void	integer_validation(int argc, char **argv);
void	duplication_validation(t_stack *top);

/* stack_bonus.c */
void	init_stack(t_stack **top, int argc, char **argv);
void	push(t_stack **top, int data);
int		pop(t_stack **top);
void	print_stack(t_stack *top);

/* push_bonus.c */
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);

/* swap_bonus.c */
int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);

/* rotate_bonus.c */
int		ra(t_stack **a);
int		rb(t_stack **b);
int		rr(t_stack **a, t_stack **b);

/* reverse_rotate_bonus.c */
int		rra(t_stack **a);
int		rrb(t_stack **b);
int		rrr(t_stack **a, t_stack **b);
t_stack	*get_last_node(t_stack *top);

#endif
