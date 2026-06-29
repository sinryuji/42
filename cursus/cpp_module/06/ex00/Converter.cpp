/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongki <hyeongki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:00:06 by hyeongki          #+#    #+#             */
/*   Updated: 2023/01/15 14:23:34 by hyeongki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <cctype>

/*
 * -------------------------- Constructor --------------------------
 */

Converter::Converter(void)
{

}

Converter::Converter(const Converter& origin)
{
	*this = origin;
}

Converter::Converter(const std::string& input)
{
	this->setCharVal(0);
	this->setIntVal(0);
	this->setFloatVal(0);
	this->setDoubleVal(0);
	convert(input);
}

/*
 * -------------------------- Destructor ---------------------------
 */

Converter::~Converter(void) {}

/*
 * -------------------------- Operator -----------------------------
 */

Converter& Converter::operator=(const Converter& origin)
{
	if (this != &origin)
		*this = origin;
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const Converter& converter)
{
	try {
		out << "char: ";
		std::string	str(1, converter.getCharVal());
		str.insert(0, "'");
		str.append("'");
		out << str << "\n";
	} catch(std::exception& e) {
		out << e.what() << "\n";
	}
	try {
		out << "int: " << converter.getIntVal() << "\n";
	} catch(std::exception& e) {
		out << e.what() << "\n";
	}
	try {
		out << "float: " << converter.getFloatVal();
		if (converter.getFloatVal() - static_cast<int>(converter.getFloatVal()) == 0)
			out << ".0f\n";
		else
			out << "f\n";
	} catch(std::exception& e) {
		out << e.what() << "\n";
	}
	try {
		out << "double: " << converter.getDoubleVal();
		if (converter.getDoubleVal() - static_cast<int>(converter.getDoubleVal()) == 0)
			out << ".0";
	} catch(std::exception& e) {
		out << e.what();
	}
	return out;
}

/*
 * -------------------------- Getter -------------------------------
 */

char	Converter::getCharVal(void) const
{
	if (this->doubleVal > std::numeric_limits<char>::max() ||
			this->doubleVal < std::numeric_limits<char>::min())
		throw ConvertImpossibleException();
	if (isnan(this->doubleVal) || isinf(this->doubleVal))
		throw ConvertImpossibleException();
	if (!std::isprint(this->charVal))
		throw NonDisplayableException();
	return this->charVal;
}

int		Converter::getIntVal(void) const
{
	if (isnan(this->doubleVal) || isinf(this->doubleVal))
		throw ConvertImpossibleException();
	if (this->doubleVal > std::numeric_limits<int>::max() ||
			this->doubleVal < std::numeric_limits<int>::min())
		throw ConvertImpossibleException();
	return this->intVal;
}

float	Converter::getFloatVal(void) const
{
	if (isnan(this->doubleVal))
		throw NanfException();
	if (isinf(this->doubleVal))
	{
		if (this->doubleVal < 0)
			throw MInffException();
		else
			throw InffException();
	}
	return this->floatVal;
}

double	Converter::getDoubleVal(void) const
{
	if (isnan(this->doubleVal))
		throw NanException();
	if (isinf(this->doubleVal))
	{
		if (this->doubleVal < 0)
			throw MInfExcepion();
		else
			throw InfException();
	}
	return this->doubleVal;
}

/*
 * -------------------------- Setter -------------------------------
 */

void	Converter::setCharVal(char charVal)
{
	this->charVal = charVal;
}

void	Converter::setIntVal(int intVal)
{
	this->intVal = intVal;
}

void	Converter::setFloatVal(float floatVal)
{
	this->floatVal = floatVal;
}

void	Converter::setDoubleVal(double doubleVal)
{
	this->doubleVal = doubleVal;
}

/*
 * -------------------------- Overriding ---------------------------
 */

const char* Converter::ConvertImpossibleException::what() const throw()
{
	return "impossible";
}

const char* Converter::NonDisplayableException::what() const throw()
{
	return "Non displayable";
}

const char* Converter::NanException::what() const throw()
{
	return "nan";
}

const char* Converter::NanfException::what() const throw()
{
	return "nanf";
}

const char* Converter::InfException::what() const throw()
{
	return "inf";
}

const char* Converter::InffException::what() const throw()
{
	return "inff";
}

const char* Converter::MInfExcepion::what() const throw()
{
	return "-inf";
}

const char* Converter::MInffException::what() const throw()
{
	return "-inff";
}

const char* Converter::AllImporssibleException::what() const throw()
{
	return "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible";
}

/*
 * -------------------------- Function -----------------------------
 */

void	Converter::convert(const std::string& input)
{
	if (isPseudo(input))
	{
		toPseudo(input);
		return;
	}
	if (isChar(input))
	{
		this->toChar(input[0]);
		return;
	}
	this->setIntVal(atoi(input.c_str()));
	if (isFloat(input))
	{
		float f = atof(input.c_str());
		this->setFloatVal(f);
		this->setDoubleVal(static_cast<double>(f));
	}
	else
	{
		double d = strtod(input.c_str(), NULL);
		this->setDoubleVal(d);
		this->setFloatVal(static_cast<double>(d));
	}
}

bool	Converter::isChar(const std::string& input)
{
	return (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]));
}

bool	Converter::isFloat(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]) && input[i] != '.' && input[i] != 'f' && input[i] != '-')
			throw AllImporssibleException();
	}
	size_t dot = input.find('.');
	size_t rDot = input.rfind('.');
	if (dot != rDot)
		throw AllImporssibleException();
	if (input[input.length() - 1] != 'f')
		return false;
	return true;
}

bool	Converter::isPseudo(const std::string& input)
{
	return (input == "-inff" || input == "+inff" || input == "nanf" ||
			input == "-inf" || input == "+inf" || input == "nan");
}

void	Converter::toPseudo(const std::string& input)
{
	if (input == "nan" || input == "nanf")
		this->setDoubleVal(NAN);
	else if (input[0] == '-')
		this->setDoubleVal(-INFINITY);
	else
		this->setDoubleVal(INFINITY);
}

void	Converter::toChar(const char& ch)
{
	this->setCharVal(ch);
	this->setIntVal(static_cast<int>(ch));
	this->setFloatVal(static_cast<float>(ch));
	this->setDoubleVal(static_cast<double>(ch));
}
