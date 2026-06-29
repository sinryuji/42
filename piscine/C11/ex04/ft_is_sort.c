/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:36:58 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/25 17:00:37 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	is_sorted;

	i = 0;
	is_sorted = 1;
	while (i < length - 1 && is_sorted)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			is_sorted = 0;
		i++;
	}
	i = 0;
	while (i < length - 1 && is_sorted == 0)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}
