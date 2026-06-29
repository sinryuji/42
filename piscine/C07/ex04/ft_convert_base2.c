/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:56:59 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/20 20:26:40 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_result_len(long long n, int base_len)
{	
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long long n, char *base, int base_len)
{
	char		*result;
	long long	digit;
	int			i;

	result = malloc(sizeof(char) * get_result_len(n, base_len));
	digit = 1;
	i = 0;
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
		i++;
	}
	while (n / digit >= base_len)
		digit *= base_len;
	while (digit != 0)
	{
		result[i] = base[n / digit];
		n -= (n / digit) * digit;
		digit /= base_len;
		i++;
	}
	result[i] = '\0';
	return (result);
}
