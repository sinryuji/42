/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:24:52 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/20 20:27:26 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
char	*ft_itoa_base(long long n, char *base, int base_len);

int	check_base(char *base)
{
	int	i;
	int	j;
	int	flag1;
	int	flag2;

	i = 0;
	flag1 = 0;
	flag2 = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32)
			flag1 = 1;
		while (base[j])
		{
			if (base[i] == base[j])
				flag2 = 1;
			j++;
		}
		i++;
	}
	if (i <= 1 || flag1 || flag2)
		return (0);
	return (i);
}

int	*iterate_base(char c, char *base)
{
	int			i;
	static int	result[2];

	i = 0;
	result[0] = 0;
	result[1] = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			result[0] = i;
			result[1] = 1;
			return (result);
		}
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base, int	base_len)
{
	int	result;
	int	*value;

	result = 0;
	while (*str)
	{
		value = iterate_base(*str, base);
		if (!value[1])
			break ;
		result *= base_len;
		result += value[0];
		str++;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		m_flag;
	int		n;
	char	*result;

	if (!check_base(base_from) || !check_base(base_to))
		return (NULL);
	while (*nbr <= 32)
		nbr++;
	m_flag = 1;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			m_flag *= -1;
		nbr++;
	}
	n = ft_atoi_base(nbr, base_from, check_base(base_from)) * m_flag;
	result = ft_itoa_base(n, base_to, check_base(base_to));
	return (result);
}
