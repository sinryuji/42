/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:59:57 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/17 14:21:05 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T*		arr;
		size_t	_size;

	public:
		Array(void) : arr(NULL), _size(0) {}
		Array(unsigned int size) : arr(new T[size]), _size(size) {}
		Array(const Array& origin) : arr()
		{
			if (origin.size() > 0)
			{
				this->arr = new T[origin.size()];
				for (size_t i = 0; i < origin.size(); i++)	
					this->arr[i] = origin[i];
				this->_size = origin.size();
			}
			else
			{
				this->arr = NULL;
				this->_size = 0;
			}
		}
		~Array(void)
		{
			delete[] this->arr;
		}
		Array&	operator=(const Array& origin)
		{
			if (this == &origin)
				return *this;
			if (this->size() > 0)
				delete[] this->arr;
			if (origin.size() > 0)
			{
				this->arr = new T[origin.size()];
				for (size_t i = 0; i < origin.size(); i++)	
					this->arr[i] = origin[i];
				this->_size = origin.size();
			}
			return *this;
		}
		T&	operator[](const size_t i)
		{
			if (i >= this->size())
				throw OutOfRangeException();
			return this->arr[i];
		}
		const T&	operator[](const size_t i) const
		{
			if (i >= this->size())
				throw OutOfRangeException();
			return this->arr[i];
		}
		size_t	size(void) const
		{
			return this->_size;
		}
		class	OutOfRangeException : public std::exception
		{
			public:
				const char* what(void) const throw()
				{
					return "Index out of range";
				}
		};
};

#endif
