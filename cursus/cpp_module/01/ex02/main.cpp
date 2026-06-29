/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:32:14 by hyeongki          #+#    #+#             */
/*   Updated: 2022/12/25 19:41:28 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "str address:			" << &str << std::endl;
	std::cout << "stringPTR address:		" << &stringPTR << std::endl;
	std::cout << "stringREF address:		" << &stringREF << std::endl;

	std::cout << "str value:			" << str << std::endl;
	std::cout << "stringPTR value:		" << stringPTR << std::endl;
	std::cout << "stringREF value:		" << stringREF << std::endl;
	return 0;
}
