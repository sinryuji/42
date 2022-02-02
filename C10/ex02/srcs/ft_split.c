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

#include "ft_tail.h"

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
		if (sep_check(str[i - 1], charset) && !sep_check(str[i], charset))
			cnt++;
		i++;
	}
	return (cnt);
}

char **ft_split(char *str, char *charset)
{
	char	**result;
	int str_index;
	int word_index;
	int result_index;
	
	result = malloc((get_word_cnt(str, charset) + 1) * sizeof(char *));
	str_index = 0;
	result_index = 0;
	while (str[str_index])
	{
	    if (sep_check(str[str_index], charset))
		str_index++;
	    else 
	    {
		word_index = 0;
		while (!sep_check(str[str_index], charset) && str[str_index])
		{
		    str_index++;
		    word_index++;
		}
		result[result_index] = ft_strdup(&str[str_index - word_index], word_index);
		result_index++;
	    }
	}
	result[result_index] = 0;
	return (result);
}
