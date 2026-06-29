/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:46:26 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/19 10:41:33 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iterator>

template <typename T>
typename T::iterator easyfind(T& container, int val)
{
	typename T::iterator	begin = container.begin();

	while (begin != container.end())
	{
		if (*begin == val)
			return begin;
		++begin;
	}
	return container.end();
}

#endif
