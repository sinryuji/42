/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 04:05:43 by jkong             #+#    #+#             */
/*   Updated: 2022/01/23 21:45:42 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#include <stdlib.h>

int	resolve_init(t_resolve *this, int argc, char **argv)
{
	char	*str;

	if (argc == 0)
		return (0);
	else if (argc == 2)
	{
		this->reference_path = DEFAULT_PATH;
		this->convert_input = argv[1];
	}
	else if (argc == 3)
	{
		this->reference_path = argv[1];
		this->convert_input = argv[2];
	}
	else
		return (0);
	str = this->convert_input;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	str = this->convert_input;
	return (resolve_make_table(this, str));
}

int	resolve_make_table(t_resolve *this, char *str)
{
	int		*tab;
	int		len;
	int		i;

	len = ft_strlen(str);
	this->tab_size = (len + (CIPHER_UNIT - 1)) / CIPHER_UNIT;
	tab = malloc(sizeof(int) * this->tab_size);
	if (tab == NULL)
		return (0);
	this->tab = tab;
	i = 0;
	while (i < len)
		*tab++ = table_element(&i, str, len);
	return (1);
}

int	resolve_try_doing(t_resolve *this, t_dictionary	*dict)
{
	int	i;
	int	n;
	int	zero;

	i = 0;
	zero = 1;
	while (i < this->tab_size)
	{
		n = this->tab[i++];
		if (n == 0)
			continue ;
		zero = 0;
		if (!resolve_try_sub(this, dict, n))
			return (0);
		n = -(((this->tab_size - 1) - (i - 1)) * CIPHER_UNIT);
		if (i < this->tab_size - 1)
			if (!append(this, dict, n))
				return (0);
	}
	if (zero)
		if (!append(this, dict, 0))
			return (0);
	return (1);
}

int	resolve_try_sub(t_resolve *this, t_dictionary	*dict, int n)
{
	if (n / 100 > 0)
	{
		if (!append(this, dict, n / 100))
			return (0);
		if (!append(this, dict, 100))
			return (0);
		n %= 100;
	}
	if (n != 0)
	{
		if (n < TRADITION_MAX)
		{
			if (!append(this, dict, n))
				return (0);
		}
		else
		{
			if (!append(this, dict, (n / 10) * 10))
				return (0);
			if (n % 10 > 0)
				if (!append(this, dict, n % 10))
					return (0);
		}
	}
	return (1);
}
