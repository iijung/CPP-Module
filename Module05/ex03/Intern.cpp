/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:20:14 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/11 14:50:24 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

Intern::~Intern(void)
{
}

Intern::Intern(void)
{
}

Intern::Intern(const Intern &obj)
{
	(void)obj;
}

Intern&	Intern::operator=(const Intern &obj)
{
	if (this == &obj)
		return (*this);
	new (this) Intern(obj);
	return (*this);
}

/* ************************************************************************** */
// Non-Requirement
/* ************************************************************************** */

const std::string	Intern::_form_names[Intern::MAX_FORM_TYPE] =
{
	[FORM_NOT_FOUND] = "",
	[SHRUBBERY_CREATION] = "shrubbery creation",
	[ROBOTOMY_REQUEST] = "robotomy request",
	[PRESIDENTIAL_PARDON] = "presidential pardon",
};

Intern::e_form_type	Intern::getFormType(std::string name)
{
	for (int i = 0; i < MAX_FORM_TYPE; i++)
	{
		if (name.compare(this->_form_names[static_cast<e_form_type>(i)]) == 0)
			return (static_cast<e_form_type>(i));
	}
	return (FORM_NOT_FOUND);
}

std::string	Intern::getFormName(Intern::e_form_type type)
{
	if (type == MAX_FORM_TYPE)
		return (Intern::_form_names[FORM_NOT_FOUND]);
	return Intern::_form_names[type];
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

AForm*	Intern::makeForm(std::string name, std::string target)
{
	const e_form_type	type = this->getFormType(name);

	switch(type)
	{
		case SHRUBBERY_CREATION:
			return (new ShrubberyCreationForm(target));
		case ROBOTOMY_REQUEST:
			return (new RobotomyRequestForm(target));
		case PRESIDENTIAL_PARDON:
			return (new PresidentialPardonForm(target));
		default:
			break ;
	}
	return (NULL);
}
