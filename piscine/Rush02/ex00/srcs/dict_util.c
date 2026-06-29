/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:42:11 by jkong             #+#    #+#             */
/*   Updated: 2022/01/25 14:40:29 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdlib.h>

int	table_element(int *i, char *str, int len)
{
	char	tmp[CIPHER_UNIT + 1];
	int		j;

	j = 0;
	while (j < CIPHER_UNIT)
	{
		if (*i == 0 && j < (CIPHER_UNIT - len % CIPHER_UNIT) % CIPHER_UNIT) // 이 부분 애매쓰
			tmp[j] = '0';
		else
			tmp[j] = str[(*i)++];
		j++;
	}
	tmp[j] = '\0';
	return (ft_atoi(tmp));
}

char	*substring(char *str, int begin, int end)
{
	char	*result;
	int		len;
	int		i;

	if (end == -1)
		end = ft_strlen(str);
	len = end - begin;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[begin + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	parse_pair(char *str, char **key, char **value)
{
	int			i;
	t_int_range	key_range;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (0);
	key_range.begin = i;
	while (ft_isdigit(str[i]))
		i++;
	key_range.end = i;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == ':')
		i++;
	else
		return (0);
	while (ft_isspace(str[i]))
		i++;
	*key = substring(str, key_range.begin, key_range.end);
	*value = substring(str, i, -1);
	return (1);
}

int	calc_key(char *key)
{
	int	result;
	int	i;
	int	n;

	if (key[0] == '1')
	{
		i = 0;
		n = 0;
		while (key[1 + i])
		{
			if (key[1 + i] == '0')
				n++;
			else
				break ;
			i++;
		}
		if (n >= CIPHER_UNIT && i == n)
			return (-n);
	}
	result = ft_atoi(key);
	return (result);
}

int	append(t_resolve *res, t_dictionary *dict, int key)
{
	char		*str;
	t_str_chain	*new_chain;

	str = dictionary_get_value(dict, key);
	if (str == NULL)
		return (0);
	new_chain = malloc(sizeof(t_str_chain));
	new_chain->str = str;
	new_chain->length = ft_strlen(str);
	new_chain->offset = 0;
	new_chain->next = NULL;
	if (res->tail)
		res->tail->next = new_chain;
	else
		res->head = new_chain;
	res->tail = new_chain;
	return (1);
}
