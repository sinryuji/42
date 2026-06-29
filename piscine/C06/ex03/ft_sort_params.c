/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:06:31 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/19 19:39:16 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	addr_swap(char **av, int j)
{
	char	*tmp;

	tmp = av[j];
	av[j] = av[j + 1];
	av[j + 1] = tmp;
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	av_print(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 1;
		while (j < ac - i)
		{	
			if (ft_strcmp(av[j], av[j + 1]) > 0)
				addr_swap(av, j);
			j++;
		}
		i++;
	}
	av_print(ac, av);
}
