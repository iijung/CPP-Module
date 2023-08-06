/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:11:03 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/06 15:45:05 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iomanip>

void	err_increment(void)
{
	Bureaucrat	high("high", 1);

	std::cout << high << std::endl;
	high.increment();
	std::cout << high << std::endl;
	high.decrement();
	std::cout << high << std::endl;
}

void	err_decrement(void)
{
	Bureaucrat	low("low", 150);

	std::cout << low << std::endl;
	low.decrement();
	std::cout << low << std::endl;
	low.increment();
	std::cout << low << std::endl;
}

void	err_constructor(void)
{
	try
	{
		Bureaucrat	high("high", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	low("low", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	err_increment();
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	err_decrement();
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	err_constructor();
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	return (0);
}
