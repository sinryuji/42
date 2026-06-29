/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:21:31 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/16 19:19:59 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	alpha_check(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	while (str[i] != '\0')
	{
		if (!alpha_check(str[i]))
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}
