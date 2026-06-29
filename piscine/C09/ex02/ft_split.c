/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:28:00 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/22 17:04:38 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src, int n)
{
	char	*result;
	int		i;

	result = malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	sep_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	get_word_cnt(char *str, char *charset)
{
	int	i;
	int	cnt;

	i = 1;
	cnt = 0;
	if (!sep_check(str[0], charset))
		cnt++;
	while (str[i])
	{
		if (sep_check(str[i - 1], charset) && !sep_check(str[i], charset))
			cnt++;
		i++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	result = malloc((get_word_cnt(str, charset) + 1) * sizeof(char *));
	i = 0;
	k = 0;
	while (str[i])
	{
		if (sep_check(str[i], charset))
			i++;
		else
		{
			j = 0;
			while (!sep_check(str[i], charset) && str[i])
			{
				i++;
				j++;
			}
			result[k++] = ft_strdup(&str[i - j], j);
		}
	}
	result[k] = 0;
	return (result);
}
