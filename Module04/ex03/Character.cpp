/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:22:01 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 04:08:21 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

Character::~Character(void)
{
	std::cout << "Character " << this->_name << " destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_slot[i];
}

Character::Character(void): _name(NULL)
{
	std::cout << "Character " << this->_name << " default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character " << this->_name << " constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}


Character::Character(const Character& obj): _name(obj.getName())
{
	std::cout << "Character " << this->_name << " copy constructor called" << std::endl;
	*this = obj;
}

Character& Character::operator=(const Character& obj)
{
	this->_name = obj.getName();
	std::cout << "Character " << this->_name << " copy constructor called" << std::endl;
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

std::string const &	Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
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

void	Character::unequip(int idx)
{
	if (0 <= idx && idx < 4)
		this->_slot[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx < 4)
	{
		if (this->_slot[idx])
			this->_slot[idx]->use(target);
	}
}

/* ************************************************************************** */
// Etc
/* ************************************************************************** */

AMateria*	Character::getSlot(int idx) const
{
	if (0 <= idx && idx < 4)
		return (this->_slot[idx]);
	return (NULL);
}
