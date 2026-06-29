/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:00:05 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/13 15:22:59 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	srand(time(NULL));
	int ran = rand() % 3;
	if (ran % 3 == 0)
	{
		std::cout << "generate A" << std::endl;
		return new A;
	}
	else if (ran % 3 == 1)
	{
		std::cout << "generate B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "generate C" << std::endl;
		return new C;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "this pointer is A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "this pointer is B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "this pointer is C" << std::endl;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "this reference is A" << std::endl;
		(void)a;
		return ;
	} catch (std::exception&) {}

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "this reference is B" << std::endl;
		(void)b;
		return ;
	} catch (std::exception&) {}

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "this reference is C" << std::endl;
		(void)c;
		return ;
	} catch (std::exception&) {}
}

int	main(void)
{
	Base* base = generate();
	identify(base);
	identify(*base);
}
