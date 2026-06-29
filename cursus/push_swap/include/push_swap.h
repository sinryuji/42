/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:21:01 by hyeongki          #+#    #+#             */
/*   Updated: 2022/09/09 21:06:20 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	int	depth;
	int	n;
	int	pow;
	int	root;
	int	cnt;
}	t_info;

/* push_swap.c */
int		check_sort(t_stack *top);

/* data_validation */
void	integer_validation(int argc, char **argv);
void	duplication_validation(t_stack *top);

/* stack.c */
void	init_stack(t_stack **top, int argc, char **argv);
void	push(t_stack **top, int data);
int		pop(t_stack **top);
void	print_stack(t_stack *top);

/* push.c */
int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);

/* swap.c */
int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);

/* rotate.c */
int		ra(t_stack **a);
int		rb(t_stack **b);
int		rr(t_stack **a, t_stack **b);

/* reverse_rotate.c */
int		rra(t_stack **a);
int		rrb(t_stack **b);
int		rrr(t_stack **a, t_stack **b);

/* linked_list.c */
t_stack	*get_last_node(t_stack *top);
int		get_list_length(t_stack *top);
t_stack	*get_index_node(t_stack *top, int i);
int		get_node_index(t_stack *current, t_stack *top);

/* merge_sort.c */
void	merge_sort(t_stack **a, t_stack **b);
int		get_size(int pow, int i, int n);
int		get_ascending(int pow, int i);

/* triangle_a.c */
int		make_triangle_a(t_stack **a, t_stack **b, int size, int ascending);

/* triangle_b.c */
int		make_triangle_b(t_stack **a, t_stack **b, int size, int ascending);

/* merge_01.c */
void	merge(t_stack **a, t_stack **b, t_info info);

/* merge_02.c */
void	merge_ascending_a_to_b(t_stack **a, t_stack **b, t_info info, int i);
void	merge_descending_a_to_b(t_stack **a, t_stack **b, t_info info, int i);
void	merge_ascending_b_to_a(t_stack **a, t_stack **b, t_info info, int i);
void	merge_descending_b_to_a(t_stack **a, t_stack **b, t_info info, int i);

/* get_info.c */
int		get_depth(int n);
int		get_size(int pow, int i, int n);
int		get_ascending(int pow, int i);

/* small_case.c */
int		small_case(t_stack **a, t_stack **b, int n);

#endif
