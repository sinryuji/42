/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:29:29 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/19 11:03:39 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Span.hpp"
#include <algorithm>

/*
 * -------------------------- Constructor --------------------------
 */

Span::Span(void) : size(0) {}

Span::Span(unsigned int n) : size(n) {}

Span::Span(const Span& origin) : numbers(origin.numbers), size(origin.size) {}

/*
 * -------------------------- Destructor ---------------------------
 */

Span::~Span(void) {}

/*
 * -------------------------- Operator -----------------------------
 */

Span& Span::operator=(const Span& origin)
{
	if (this != &origin)
	{
		this->numbers = origin.numbers;
		this->size = origin.size;
	}
	return *this;
}

/*
 * -------------------------- Overring -----------------------------
 */

const char* Span::SpanIsFullException::what(void) const throw()
{
	return "Span is full";
}

const char* Span::NumberExistException::what(void) const throw()
{
	return "This number is already exist";
}

const char* Span::TooSmallException::what(void) const throw()
{
	return "Span is too small";
}

/*
 * -------------------------- Function -----------------------------
 */

void	Span::addNumber(int n)
{
	if (this->numbers.size() >= this->size)
		throw SpanIsFullException();
	if (find(this->numbers.begin(), this->numbers.end(), n) != this->numbers.end())
		throw NumberExistException();
	this->numbers.push_back(n);
}

int	Span::shortestSpan() const
{
	if (this->numbers.size() < 2)
		throw TooSmallException();
	std::vector<int> tmp(this->numbers);
	std::sort(tmp.begin(), tmp.end());
	int	ret = *(tmp.begin() + 1) - *tmp.begin();
	for (std::vector<int>::iterator it = tmp.begin() + 1; it != tmp.end() - 1; it++)
	{
		if (*(it + 1) - *it < ret)
			ret = *(it + 1) - *it;
	}
	return ret;
}

int	Span::longestSpan()	const
{
	if (this->numbers.size() < 2)
		throw TooSmallException();
	return (*std::max_element(this->numbers.begin(), this->numbers.end()) - \
			*std::min_element(this->numbers.begin(), this->numbers.end()));
}
