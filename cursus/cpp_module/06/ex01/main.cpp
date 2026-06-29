/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:19:50 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/15 13:56:25 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

struct Data
{
	int	value;
};

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int	main(void)
{
	Data		data;
	Data*		data2;
	uintptr_t	ptr;

	data.value = 10;
	ptr = serialize(&data);
	std::cout << "data value: " << data.value << std::endl;
	std::cout << "data ptr(hexa): " << &data << std::endl;
	std::cout << "data ptr(decimal): " << ptr << std::endl;

	std::cout << "========================" << std::endl;

	data2 = deserialize(ptr);
	std::cout << "data value: " << data2->value << std::endl;
	std::cout << "data ptr(hexa): " << data2 << std::endl;
	std::cout << "data ptr(decimal): " << serialize(data2) << std::endl;

	return 0;
}
