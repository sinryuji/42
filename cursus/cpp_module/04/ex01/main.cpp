/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:41:34 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/06 02:52:02 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	
	std::cout << "=======================================" << std::endl;

	const int	arrSize = 6;
	Animal*	arr[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		if (i < arrSize / 2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	std::cout << "=======================================" << std::endl;

	for (int i = 0; i < arrSize; i++)
		delete arr[i];

	std::cout << "=======================================" << std::endl;

	Cat* cat = new Cat();
	Cat kitty = Cat();
	cat->getBrain()->setIdea("happy", 0);
	std::cout << "kitty 0 idea: " << kitty.getBrain()->getIdea(0) << std::endl;
	kitty = *cat;
	std::cout << "kitty 0 idea: " << kitty.getBrain()->getIdea(0) << std::endl;
	delete cat;
	std::cout << "cat delete!!"<< std::endl;
	std::cout << "kitty 0 idea: " << kitty.getBrain()->getIdea(0) << std::endl;

	return 0;
}
