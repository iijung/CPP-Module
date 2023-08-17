/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:16:27 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/15 01:51:11 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALAR_CONVERTER_H__
# define __SCALAR_CONVERTER_H__
#include <iostream>	// std::cout
#include <cstdlib>	// std::strtod
#include <cctype>	// std::isprint
#include <cmath>	// std::isnan
#include <limits>	// std::numeric_limits
#include <iomanip>	// std::setprecision

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter& operator=(const ScalarConverter &obj);
		virtual ~ScalarConverter(void);
	public:
		static void	convert(const std::string &literal);
};

#endif /* __SCALAR_CONVERTER_H__ */
