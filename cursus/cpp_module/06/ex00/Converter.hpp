/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:59:12 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/15 11:02:26 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <fstream>
# include <cmath>
# include <cstdlib>
# include <limits>

class Converter
{
	private:
		char	charVal;
		int		intVal;
		float	floatVal;
		double	doubleVal;
		bool	isChar(const std::string& input);
		bool	isPseudo(const std::string& input);
		bool	isFloat(std::string input);
		void	toPseudo(const std::string& input);
		void	toChar(const char& ch);

	public:
		Converter(void);
		Converter(const std::string& input);
		Converter(const Converter& origin);
		~Converter(void);
		Converter& operator=(const Converter& origin);
		char	getCharVal(void) const;
		int		getIntVal(void) const;
		float	getFloatVal(void) const;
		double	getDoubleVal(void) const;
		void	setCharVal(char charVal);
		void	setIntVal(int intVal);
		void	setFloatVal(float floatVal);
		void	setDoubleVal(double doubleVal);
		void	convert(const std::string& input);
		class	ConvertImpossibleException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	NonDisplayableException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	NanException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	NanfException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	InfException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	InffException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	MInfExcepion : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	MInffException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	AllImporssibleException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Converter& converter);

#endif
