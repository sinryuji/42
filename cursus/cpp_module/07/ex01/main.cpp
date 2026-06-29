/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:45:48 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/15 21:51:06 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int	intArr[5] = {0, 1, 2, 3, 5};
	std::string	strArr[5] = {"kim", "lee", "park", "choi", "jeong"};

	iter(intArr, 5, &print);
	iter(strArr, 5, &print);
}
