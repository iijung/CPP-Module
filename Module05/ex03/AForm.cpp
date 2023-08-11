/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:05:57 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/11 16:20:51 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

AForm::~AForm(void)
{
}

AForm::AForm(void)
	: _name("default"),
	_sign_grade(150),
	_execute_grade(150)
{
	this->_signed = false;
}

AForm::AForm(std::string name, std::string target, int sign_grade, int execute_grade)
	:_name(name),
	_target(target),
	_sign_grade(sign_grade),
	_execute_grade(execute_grade)
{
	this->_signed = false;
	if (this->_sign_grade < 1 || this->_execute_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_sign_grade > 150 || this->_sign_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm& obj):
	_name(obj.getName()),
	_target(obj.getTarget()),
	_sign_grade(obj.getSignGrade()),
	_execute_grade(obj.getExecuteGrade())
{
	*this = obj;
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this == &obj)
		return (*this);
	this->_signed = obj._signed;
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high exception");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low exception");
}

const std::string	AForm::getName(void) const
{
	return (this->_name);
}

const std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int	AForm::getExecuteGrade(void) const
{
	return (this->_execute_grade);
}

std::ostream&	operator<<(std::ostream& out, const AForm& obj)
{
	out << "║"
		<< std::setw(3) << (obj.getSigned()? "✅" : "❌")
		<< "│"
		<< std::setw(7) << obj.getSignGrade()
		<< "│"
		<< std::setw(7) << obj.getExecuteGrade()
		<< "│"
		<< std::setw(30) << obj.getName()
		<< "│"
		<< std::setw(27) << obj.getTarget()
		<< "║" << std::endl;
	return (out);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->getSignGrade() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}
