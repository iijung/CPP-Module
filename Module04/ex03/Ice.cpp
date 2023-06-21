/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 03:42:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 22:28:57 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& obj): AMateria(obj.getType())
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = obj;
}

Ice& Ice::operator=(const Ice& obj)
{
	std::cout << "Ice copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->_type = obj.getType();
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

Ice*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}
