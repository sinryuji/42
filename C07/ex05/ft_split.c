/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:28:00 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/20 20:29:46 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	int cnt;
	
	i = 1;
	cnt = 0;
	if (!sep_check(str[0], charset))
		cnt++;
	while (str[i])
	{
		if (sep_ckeck(str[i - 1], charset) && !sep_check(str[i]))
			cnt++;
		i++;
	}
	return (cnt);
}

char **ft_split(char *str, char *charset)
{
	char	**result;
	
			result = malloc(
}
