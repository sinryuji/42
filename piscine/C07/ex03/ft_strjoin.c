/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:51:20 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/20 15:40:30 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	len;
	int i;

	i = 0;
	len = ft_strlen(sep) * (size - 1);
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	printf("%d\n", len);
	return (len);
}

void	*val_set(int size, char **strs, char *sep, char *result)
{
    int	i;
    int	j;
    int k;

    i = 0;
    k = 0;
    while (i < size)
    {
	j = 0;
	if (strs[i])
	{
	    while (strs[i][j])
	    {
		result[k] = strs[i][j];
		k++;
		j++;
	    }
	}
	j = 0;
	if (sep)
	{
	    while (sep[j] && i < size - 1)
	    {
		result[k] = sep[j];
		k++;
		j++;
	    }
	    i++;
	}
    }
    result[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		len;
	int		i;
	int j;

	if (size == 0)
	{
		result = malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	len = ft_total_len(size, strs, sep);
	printf("%d\n", len);
	result = malloc(sizeof(char) * (len + 1));
	val_set(size, strs, sep, result);
	return (result);
}


int main(int ac, char **av)
{
    printf("%s\n", ft_strjoin(ac, av, ", "));
}

