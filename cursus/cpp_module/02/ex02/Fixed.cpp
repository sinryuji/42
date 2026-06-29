/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:18:29 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/01 17:39:48 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
 * -------------------------- Constructor -----------------------------
 */

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed& origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bits;	
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bits));
}

/*
 * -------------------------- Operator -----------------------------
 */

Fixed&	Fixed::operator=(const Fixed& origin)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin)
		this->value = origin.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator>(Fixed const& fixed) const
{
	return this->getRawBits() > fixed.getRawBits();
}

bool	Fixed::operator<(Fixed const& fixed) const
{
	return this->getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>=(Fixed const& fixed) const
{
	return this->getRawBits() >= fixed.getRawBits();
}

bool	Fixed::operator<=(Fixed const& fixed) const
{
	return this->getRawBits() <= fixed.getRawBits();
}

bool	Fixed::operator==(Fixed const& fixed) const
{
	return this->getRawBits() == fixed.getRawBits();
}

bool	Fixed::operator!=(Fixed const& fixed) const
{
	return this->getRawBits() != fixed.getRawBits();
}

const Fixed	Fixed::operator+(Fixed const& fixed) const
{
	Fixed ret(this->toFloat() + fixed.toFloat());
	return ret;
}

const Fixed	Fixed::operator-(Fixed const& fixed) const
{
	Fixed ret(this->toFloat() - fixed.toFloat());
	return ret;
}

const Fixed	Fixed::operator*(Fixed const& fixed) const
{
	Fixed ret(this->toFloat() * fixed.toFloat());
	return ret;
}

const Fixed	Fixed::operator/(Fixed const& fixed) const
{
	Fixed ret(this->toFloat() / fixed.toFloat());
	return ret;
}

const Fixed&	Fixed::operator++(void)
{
	this->value++;
	return *this;
}

const Fixed	Fixed::operator++(int)
{
	Fixed	ret(*this);
	this->value++;
	return ret;
}

const Fixed&	Fixed::operator--(void)
{
	this->value--;
	return *this;
}

const Fixed	Fixed::operator--(int)
{
	Fixed	ret(*this);
	this->value--;
	return ret;
}

Fixed&	Fixed::min(Fixed& ref1, Fixed& ref2)
{
	if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed&	Fixed::min(Fixed const& ref1, Fixed const& ref2)
{
	if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

Fixed&	Fixed::max(Fixed& ref1, Fixed& ref2)
{
	if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed&	Fixed::max(Fixed const& ref1, Fixed const& ref2)
{
	if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}
/*
 * -------------------------- Destructor -----------------------------
 */

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
 * -------------------------- Function -----------------------------
 */

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->value / (1 << this->bits);	
}

int	Fixed::toInt(void) const
{
	return this->value >> this->bits;
}
