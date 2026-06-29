/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*   Created: 2023/01/17 21:22:53 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/17 22:24:48 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int	main(void)
{
	int arr[5] = {1, 2, 42, 4, 5};
	std::cout << "===== vector test =====" << std::endl;
	{
		std::vector<int> test(arr, arr + 5);
		std::vector<int>::iterator iter = easyfind(test, 42);
		std::cout << "[ Found ]" << std::endl;
		if (iter == test.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Found: " << *iter << std::endl;
		std::cout << "[ Not found ]" << std::endl;
		iter = easyfind(test, 24);
		if (iter == test.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Found: " << *iter << std::endl;
	}

	std::cout << "\n===== deque test =====" << std::endl;
	{
		std::deque<int> test(arr, arr + 5);
		std::deque<int>::iterator iter = easyfind(test, 42);
		std::cout << "[ Found ]" << std::endl;
		if (iter == test.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Found: " << *iter << std::endl;
		std::cout << "[ Not found ]" << std::endl;
		iter = easyfind(test, 24);
		if (iter == test.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Found: " << *iter << std::endl;
	}

	std::cout << "\n===== list test =====" << std::endl;
	{
		std::list<int> test(arr, arr + 5);
		std::list<int>::iterator iter = easyfind(test, 42);
		std::cout << "[ Found ]" << std::endl;
		if (iter == test.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Found: " << *iter << std::endl;
		std::cout << "[ Not found ]" << std::endl;
		iter = easyfind(test, 24);
		if (iter == test.end())
			std::cout << "Not found" << std::endl;
		else
			std::cout << "Found: " << *iter << std::endl;
	}
}
