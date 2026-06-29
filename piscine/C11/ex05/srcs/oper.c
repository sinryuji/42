/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:49:34 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/26 20:22:33 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	cal_add(int x, int y)
{
	return (x + y);
}

int	cal_min(int x, int y)
{
	return (x - y);
}

int	cal_mul(int x, int y)
{
	return (x * y);
}

int	cal_div(int x, int y)
{
	return (x / y);
}

int	cal_mod(int x, int y)
{
	return (x % y);
}
