/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:27:56 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/12 14:58:55 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_i;
	unsigned int	src_i;
	unsigned int	result;

	if (size == 0)
		return (get_length(src));
	if (size <= get_length(dest))
		return (size + get_length(src));
	result = get_length(dest) + get_length(src);
	dest_i = get_length(dest);
	src_i = 0;
	while (src[src_i] != '\0' && dest_i < size - 1)
	{
		dest[dest_i] = src[src_i];
		dest_i++;
		src_i++;
	}
	dest[dest_i] = '\0';
	return (result);
}
