/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:44:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/13 15:42:57 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(void)
	: _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
	: _name(obj.getName()), _grade(obj.getGrade())
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this == &obj)
		return (*this);
	new (this) Bureaucrat(obj);
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::increment(void)
{
	try
	{
		if (this->_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		this->_grade -= 1;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decrement(void)
{
	try
	{
		if (this->_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		this->_grade += 1;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (out);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high exception");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low exception");
}
