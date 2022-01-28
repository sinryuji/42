/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:25:35 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/26 20:14:31 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

int		check_oper(char *str);
void	cal_print(int x, int y, char oper, int(*fp[])(int, int));
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		check_error(char c, int y);
int		cal_add(int x, int y);
int		cal_min(int x, int y);
int		cal_mul(int x, int y);
int		cal_div(int x, int y);
int		cal_mod(int x, int y);

#endif
