/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:21:53 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 04:03:43 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_slot[i];
}

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->_slot[i];
		if (obj.getSlot(i) == NULL)
			this->_slot[i] = NULL;
		else
			this->_slot[i] = obj.getSlot(i)->clone();
	}
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] && this->_slot[i]->getType() == type)
			return (this->_slot[i]->clone());
	}
	return (NULL);
}

/* ************************************************************************** */
// Etc
/* ************************************************************************** */

AMateria*	MateriaSource::getSlot(int idx) const
{
	if (0 <= idx && idx < 4)
		return (this->_slot[idx]);
	return (NULL);
}
