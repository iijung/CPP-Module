/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 01:44:55 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 04:05:25 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& obj): AMateria(obj.getType())
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = obj;
}

Cure&	Cure::operator=(const Cure& obj)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	this->_type = obj.getType();
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

Cure*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "Cure: \"* heals " << target.getName() << "'s wounds *\"" << std::endl;
}
