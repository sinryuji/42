/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:12:55 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/01 17:39:43 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		const static	int	bits = 8;
		
	public:
		Fixed(void);
		Fixed(const Fixed& origin);
		Fixed(const int value);
		Fixed(const float value);
		Fixed&	operator=(const Fixed& origin);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		bool	operator>(Fixed const& fixed) const;
		bool	operator<(Fixed const& fixed) const;
		bool	operator>=(Fixed const& fixed) const;
		bool	operator<=(Fixed const& fixed) const;
		bool	operator==(Fixed const& fixed) const;
		bool	operator!=(Fixed const& fixed) const;
		const Fixed	operator+(Fixed const& fixed) const;
		const Fixed	operator-(Fixed const& fixed) const;
		const Fixed	operator*(Fixed const& fixed) const;
		const Fixed	operator/(Fixed const& fixed) const;
		const Fixed&	operator++(void);
		const Fixed	operator++(int);
		const Fixed&	operator--(void);
		const Fixed	operator--(int);
		static Fixed&		min(Fixed& ref1, Fixed& ref2);
		static const Fixed&	min(Fixed const& ref1, Fixed const& ref2);
		static Fixed&		max(Fixed& ref1, Fixed& ref2);
		static const Fixed&	max(Fixed const& ref1, Fixed const& ref2);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif
