/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:38:41 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/12 14:56:57 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char *str, char *to_find, int i)
{
	int	check;
	int	j;

	j = 0;
	check = 1;
	while (to_find[j] != '\0')
	{
		if (str[i] != to_find[j])
		{
			check = 0;
			break ;
		}
		j++;
		i++;
	}
	return (check);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*result;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0] && check(str, to_find, i))
		{
			result = str + i;
			break ;
		}
		i++;
	}
	return (result);
}
