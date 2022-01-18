/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:37:09 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/12 11:16:27 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_alpha(char c)
{
	int	check;

	check = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	return (check);
}

int	check_upper(char c)
{
	int	check;

	check = (c >= 'A' && c <= 'Z');
	return (check);
}

int	check_lower(char c)
{
	int	check;

	check = (c >= 'a' && c <= 'z');
	return (check);
}

int	check_number(char c)
{
	int	check;

	check = (c >= '0' && c <= '9');
	return (check);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (check_lower(str[0]))
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (check_alpha(str[i]))
		{
			if (check_alpha(str[i - 1]) || check_number(str[i - 1]))
			{
				if (check_upper(str[i]))
					str[i] += 32;
			}
			else
			{
				if (check_lower(str[i]))
					str[i] -= 32;
			}
		}
		i++;
	}
	return (str);
}
