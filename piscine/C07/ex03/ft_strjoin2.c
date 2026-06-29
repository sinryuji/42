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

	len = ft_strlen(sep) * (size - 1);
	while (size-- > 0)
		len += ft_strlen(strs[size]);
	if (len <= 0)
	    return (0);
	return (len + 1);
}

void	*ft_strcat(char *dest, char *src, char *sep, int *dest_i)
{
	int	src_i;
	int	sep_i;

	src_i = 0;
	sep_i = 0;
	while (src[src_i])
	{
		dest[*dest_i] = src[src_i];
		*dest_i = *dest_i + 1;
		src_i++;
	}
	while (sep[sep_i])
	{
		dest[*dest_i] = sep[sep_i];
		*dest_i = *dest_i + 1;
		sep_i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		len;
	int		i;
	int dest_i;

	if (size == 0)
	{
		result = malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	len = ft_total_len(size, strs, sep);
	result = malloc(sizeof(char) * len);
	if (!reuslt)
	    return (NULL);
	i = 0;
	dest_i = 0;
	while (i < size - 1)
	{
		ft_strcat(result, strs[i], sep, &dest_i);
		i++;
	}
	ft_strcat(result, strs[i], "", &dest_i);
	result[dest_i] = '\0';
	return (result);
}
