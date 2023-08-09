/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:11:03 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/10 01:37:21 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iomanip>

void	test_shrubbery(Bureaucrat &bureaucrat)
{
	ShrubberyCreationForm	form("kgnujnim");

	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}

void	test_robotomy(Bureaucrat &bureaucrat)
{
	RobotomyRequestForm		form("kgnujnim");

	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}

void	test_president(Bureaucrat &bureaucrat)
{
	PresidentialPardonForm	form("kgnujnim");

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
	test_robotomy(min);
	test_robotomy(jung);
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	test_president(min);
	test_president(jung);
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	return (0);
}
