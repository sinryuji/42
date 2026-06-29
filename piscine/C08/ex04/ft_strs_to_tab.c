/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:09:40 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/23 20:33:34 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_show_tab(struct s_stock_str *par);

char	*ft_strdup(char *src)
{
	int		len;
	char	*result;
	int		i;

	len = 0;
	while (src[len])
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock_list;

	i = 0;
	stock_list = malloc((ac + 1) * sizeof(t_stock_str));
	if (!stock_list)
		return (NULL);
	while (i < ac)
	{
		stock_list[i].size = ft_strlen(av[i]);
		stock_list[i].str = av[i];
		stock_list[i].copy = ft_strdup(av[i]);
		i++;
	}
	stock_list[i].size = 0;
	stock_list[i].str = 0;
	stock_list[i].copy = 0;
	return (stock_list);
}

int	main(int ac, char **av)
{
	ft_show_tab(ft_strs_to_tab(ac, av));
}
