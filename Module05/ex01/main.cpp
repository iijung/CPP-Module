/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:11:03 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/07 13:35:00 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iomanip>

void	low_form(Bureaucrat &bureaucrat)
{
	Form	form("low", 150, 150);

	bureaucrat.signForm(form);
}

void	high_form(Bureaucrat &bureaucrat)
{
	Form	form("high", 1, 1);

	bureaucrat.signForm(form);
}

int	main(void)
{
	Bureaucrat	bureaucrat("minjungk", 100);

	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	low_form(bureaucrat);
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	high_form(bureaucrat);
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	return (0);
}
