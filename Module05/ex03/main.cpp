/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:11:03 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/11 14:52:24 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iomanip>

void	test_shrubbery(Bureaucrat &bureaucrat, Intern &intern)
{
	std::string	name = intern.getFormName(Intern::SHRUBBERY_CREATION);
	AForm*		form = intern.makeForm(name, "target");

	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
}

void	test_robotomy(Bureaucrat &bureaucrat, Intern &intern)
{
	std::string	name = intern.getFormName(Intern::ROBOTOMY_REQUEST);
	AForm*		form = intern.makeForm(name, "target");

	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
}

void	test_president(Bureaucrat &bureaucrat, Intern &intern)
{
	std::string	name = intern.getFormName(Intern::PRESIDENTIAL_PARDON);
	AForm*		form = intern.makeForm(name, "target");

	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
}

int	main(void)
{
	Intern		intern;
	Bureaucrat	bureaucrat("minjungk", 1);

	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	test_shrubbery(bureaucrat, intern);
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	test_robotomy(bureaucrat, intern);
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	test_president(bureaucrat, intern);
	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	return (0);
}
