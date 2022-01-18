/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:10:31 by hyeongki          #+#    #+#             */
/*   Updated: 2022/01/12 12:27:21 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_i;
	unsigned int	src_i;

	dest_i = 0;
	src_i = 0;
	while (dest[dest_i] != '\0')
		dest_i++;
	while (src[src_i] != '\0' && src_i < nb)
	{
		dest[dest_i] = src[src_i];
		src_i++;
		dest_i++;
	}
	dest[dest_i] = '\0';
	return (dest);
}
