/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 03:03:12 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/10 01:33:19 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

/* ************************************************************************** */
// Orthodox Canonical Class Form 
/* ************************************************************************** */

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", "default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj)
	: AForm(obj)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this == &obj)
		return (*this);
	new (this) RobotomyRequestForm(obj);
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

int	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getExecuteGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::srand(std::time(NULL));
	std::cout << "Robotomizing the " << this->getTarget() << std::endl;
	if (std::rand() % 2)
	{
		std::cout << "[1;33mbzzzz......[0m" << std::endl;
		std::cout << "[1;36mRobotomy complete.[0m" << std::endl;
	}
	else
		std::cout << "[1;31mRobotomy failed.[0m" << std::endl;
	return (EXIT_SUCCESS);
}
