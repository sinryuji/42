/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:23:15 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/16 19:54:45 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	const int arrSize = 5;
	Array<int> intArr(arrSize);
	Array<std::string> strArr(arrSize);

	for (int i = 0; i < arrSize; i++)
		intArr[i] = i;
	strArr[0] = "hi";
	strArr[1] = "my";
	strArr[2] = "name";
	strArr[3] = "is";
	strArr[4] = "hyeongki";

	std::cout << "===== [] test =====" << std::endl;
	std::cout << "intArr: ";
	for (int i = 0; i < arrSize; i++)
		std::cout << intArr[i] << ' ';
	std::cout << std::endl;
	std::cout << "strArr: ";
	for (int i = 0; i < arrSize; i++)
		std::cout << strArr[i] << ' ';
	std::cout << std::endl;
	strArr[0] = "hello";
	std::cout << "strArr: ";
	for (int i = 0; i < arrSize; i++)
		std::cout << strArr[i] << ' ';
	std::cout << std::endl;

	std::cout << "\n===== copy constructor test =====" << std::endl;
	Array<std::string> strArr2(strArr);
	std::cout << "strArr2: ";
	for (int i = 0; i < arrSize; i++)
		std::cout << strArr2[i] << ' ';
	std::cout << std::endl;

	std::cout << "\n===== assignment operator test =====" << std::endl;
	Array<std::string> strArr3 = strArr2;
	std::cout << "strArr3: ";
	for (int i = 0; i < arrSize; i++)
		std::cout <<  strArr3[i] << ' ';
	std::cout << std::endl;
	
	std::cout << "\n===== exception test =====" << std::endl;
	try {
		intArr[-1] = 1;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		intArr[arrSize] = 1;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
