/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 03:03:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/08 07:07:11 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", "default", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
	: AForm(obj)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this == &obj)
		return (*this);
	new (this) PresidentialPardonForm(obj);
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

int	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getExecuteGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	// Informs that <target> has been pardoned by Zaphod Beeblebrox.
	return (EXIT_SUCCESS);
}
