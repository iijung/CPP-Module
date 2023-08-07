/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:05:57 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/07 13:29:40 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

Form::~Form(void)
{
	std::cout << "Form " << _name << " destructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int execute_grade):
	_name(name),
	_sign_grade(sign_grade),
	_execute_grade(execute_grade)
{
	std::cout << "Form " << _name << "constructor called" << std::endl;
	this->_signed = false;
}


Form::Form(const Form& obj):
	_name(obj.getName()),
	_sign_grade(obj.getSignGrade()),
	_execute_grade(obj.getExecuteGrade())
{
	std::cout << "Form " << _name << "copy constructor called" << std::endl;
	*this = obj;
}

Form& Form::operator=(const Form& obj)
{
	std::cout << "Form " << _name << " = " << obj.getName() << "copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->_signed = obj.getSigned();
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
	out << obj.getName() << ", form signed " << obj.getSigned() << std::endl;
	out << obj.getName() << ", form sign grade" << obj.getSignGrade() << std::endl;
	out << obj.getName() << ", form execute grade" << obj.getExecuteGrade() << std::endl;
	return (out);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->getSignGrade() < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	this->_signed = true;
}
