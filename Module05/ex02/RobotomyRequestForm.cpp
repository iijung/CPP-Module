/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 03:03:12 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/08 07:07:01 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

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
	// Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed.
	return (EXIT_SUCCESS);
}
