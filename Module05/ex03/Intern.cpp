/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:20:14 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/13 15:58:05 by minjungk         ###   ########.fr       */
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
	throw Intern::InvalidForm();
}

std::string	Intern::getFormName(int type)
{
	if (!(0 <= type && type < MAX_FORM_TYPE))
		throw Intern::InvalidForm();
	return Intern::_form_names[type];
}

const char*	Intern::InvalidForm::what() const throw()
{
	return ("Invalid form");
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm				*form;
	const e_form_type	type = this->getFormType(name);

	try
	{
		switch(type)
		{
			case SHRUBBERY_CREATION:
				form = new ShrubberyCreationForm(target);
				break ;
			case ROBOTOMY_REQUEST:
				form = new RobotomyRequestForm(target);
				break ;
			case PRESIDENTIAL_PARDON:
				form = new PresidentialPardonForm(target);
				break ;
			default:
				throw Intern::InvalidForm();
				break ;
		}
		std::cout << "Intern creates " << name << std::endl;
		return (form);
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern don't creates " << name << " because " << e.what() << std::endl;
	}
	return (NULL);
}
