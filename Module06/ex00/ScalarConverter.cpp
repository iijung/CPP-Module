/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:16:41 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/21 16:55:34 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

static void	print_char(const double value)
{
	try
	{
		char	c = static_cast<char>(value);

		if (std::isnan(value)
			|| value < std::numeric_limits<char>::min()
			|| value > std::numeric_limits<char>::max())
			throw std::invalid_argument("impossible");
		if (std::isprint(c) == false)
			throw std::invalid_argument("Non displayable");
		std::cout << "char: " << "'" << c << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "char: " << e.what() << std::endl;
	}
}

static void	print_int(const double value)
{
	try
	{
		int		i = static_cast<int>(value);
		if (std::isnan(value)
			|| value < std::numeric_limits<int>::min()
			|| value > std::numeric_limits<int>::max())
			throw std::invalid_argument("impossible");
		std::cout << "int : " << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "int: " << e.what() << std::endl;
	}
}

static void	print_float(const double value)
{
	try
	{
		float	f = static_cast<float>(value);
		if (std::isnan(value))
			throw std::invalid_argument("nanf");
		if (f == std::numeric_limits<float>::infinity())
			throw std::invalid_argument("+inff");
		if (f == -std::numeric_limits<float>::infinity())
			throw std::invalid_argument("-inff");
		std::cout << "float : " << f << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "float: " << e.what() << std::endl;
	}
}

static void	print_double(const double value)
{
	try
	{
		double	d = static_cast<double>(value);
		if (std::isnan(value))
			throw std::invalid_argument("nan");
		if (d == std::numeric_limits<double>::infinity())
			throw std::invalid_argument("+inf");
		if (d == -std::numeric_limits<double>::infinity())
			throw std::invalid_argument("-inf");
		std::cout << "double: " << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "double: " << e.what() << std::endl;
	}
}

void	ScalarConverter::convert(const std::string &literal)
{
	char	*endptr = NULL;
	double	value = std::strtod(literal.c_str(), &endptr);

	if (endptr && *endptr != '\0' && literal.length() == 1)
		value = static_cast<double>(literal.at(0));
	std::cout << std::fixed << std::setprecision(1);
	print_char(value);
	print_int(value);
	print_float(value);
	print_double(value);
}
