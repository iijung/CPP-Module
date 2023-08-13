/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:05:57 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/13 15:43:13 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

Form::~Form(void)
{
}

Form::Form(void)
	: _name("default"),
	_sign_grade(150),
	_execute_grade(150)
{
	this->_signed = false;
}

Form::Form(std::string name, int sign_grade, int execute_grade)
	:_name(name),
	_sign_grade(sign_grade),
	_execute_grade(execute_grade)
{
	this->_signed = false;
	if (this->_sign_grade < 1 || this->_execute_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_sign_grade > 150 || this->_sign_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


Form::Form(const Form& obj):
	_name(obj.getName()),
	_sign_grade(obj.getSignGrade()),
	_execute_grade(obj.getExecuteGrade())
{
	*this = obj;
}

Form& Form::operator=(const Form& obj)
{
	if (this == &obj)
		return (*this);
	this->_signed = obj._signed;
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high exception");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low exception");
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("Already signed");
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int	Form::getExecuteGrade(void) const
{
	return (this->_execute_grade);
}

std::ostream&	operator<<(std::ostream& out, const Form& obj)
{
	out << obj.getName() << ", form"
		<< " signed: " << obj.getSigned()
		<< " signgrade:" << obj.getSignGrade()
		<< " execute grade:" << obj.getExecuteGrade() << std::endl;
	return (out);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_signed)
		throw Form::AlreadySignedException();
	if (this->getSignGrade() < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	this->_signed = true;
}
