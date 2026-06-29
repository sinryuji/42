/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:16:49 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/15 21:38:33 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

//int	main(void)
//{
//	int intA = 10, intB = 20;
//	double	doubleA = 10.5, doubleB = 9.5;
//	std::string	strA = "hello", strB = "world";
//
//	std::cout << "===== swap test =====" << std::endl;
//	std::cout << "intA: " << intA << std::endl;
//	std::cout << "intB: " << intB << std::endl;
//	std::cout << "doubleA: " << doubleA << std::endl;
//	std::cout << "doubleB: " << doubleB << std::endl;
//	std::cout << "strA: " << strA << std::endl;
//	std::cout << "strB: " << strB << std::endl;
//	std::cout << "= swap! =" << std::endl;
//	swap(intA, intB);
//	swap(doubleA, doubleB);
//	swap(strA, strB);
//	std::cout << "intA: " << intA << std::endl;
//	std::cout << "intB: " << intB << std::endl;
//	std::cout << "doubleA: " << doubleA << std::endl;
//	std::cout << "doubleB: " << doubleB << std::endl;
//	std::cout << "strA: " << strA << std::endl;
//	std::cout << "strB: " << strB << std::endl;
//	
//	std::cout << "\n===== min test =====" << std::endl;
//	std::cout << "int min: " << min(intA, intB) << std::endl;
//	std::cout << "double min: " << min(doubleA, doubleB) << std::endl;
//	std::cout << "str min: " << ::min(strA, strB) << std::endl;
//
//	std::cout << "\n===== max test =====" << std::endl;
//	std::cout << "int max: " << max(intA, intB) << std::endl;
//	std::cout << "double max: " << max(doubleA, doubleB) << std::endl;
//	std::cout << "str max: " << ::max(strA, strB) << std::endl;
//}
