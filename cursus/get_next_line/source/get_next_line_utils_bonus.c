/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:37:30 by hyeongki          #+#    #+#             */
/*   Updated: 2022/07/21 19:38:29 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (i);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*result;
	int		i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s || ft_strlen(s) <= start)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ret = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!ret)
		return (NULL);
	while (i < len)
	{
		ret[i] = s[start];
		start++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;

	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
}
