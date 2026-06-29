/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:16:44 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/25 21:33:55 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_tab_length(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		tab_len;
	char	*tmp;

	i = 0;
	tab_len = get_tab_length(tab);
	while (i < tab_len)
	{
		j = 0;
		while (j < tab_len - i - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
