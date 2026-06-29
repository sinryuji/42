/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 01:24:09 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/18 17:38:48 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>

class Span
{
	private:
		std::vector<int>	numbers;
		std::size_t			size;

	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span& origin);
		~Span(void);
		Span&			operator=(const Span& origin);
		void			addNumber(int n);
		template <typename InputIterator>
		void			addNumber(InputIterator first, InputIterator last)
		{
			if (this->numbers.size() + std::distance(first, last) > this->size)
				throw SpanIsFullException();
			this->numbers.insert(this->numbers.begin(), first, last);
			std::vector<int> tmp(this->numbers);
			std::sort(tmp.begin(), tmp.end());
			if (std::adjacent_find(tmp.begin(), tmp.end()) != tmp.end())
				throw NumberExistException();
		}
		int				shortestSpan()	const;
		int				longestSpan()	const;
		class	SpanIsFullException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	NumberExistException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	TooSmallException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

#endif
