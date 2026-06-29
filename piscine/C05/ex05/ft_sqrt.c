/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:18:31 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/18 14:41:55 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned int	i;
	unsigned int	n;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 1;
	n = nb;
	while (i * i <= n)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (0);
}
