/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:11:03 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/08 07:11:29 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>

void	test_shrubbery(Bureaucrat &bureaucrat)
{
	ShrubberyCreationForm	form("target");

	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}

int	main(void)
{
	Bureaucrat	min("min", 1);
	Bureaucrat	jung("jung", 150);

	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	test_shrubbery(min);
	test_shrubbery(jung);
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	return (0);
}
