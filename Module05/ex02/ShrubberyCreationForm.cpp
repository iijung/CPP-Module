/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 03:03:05 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/08 07:08:02 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", "default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
	: AForm(obj)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this == &obj)
		return (*this);
	new (this) ShrubberyCreationForm(obj);
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

int	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getExecuteGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	// Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
	return (EXIT_SUCCESS);
}
