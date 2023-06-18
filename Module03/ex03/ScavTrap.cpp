/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:54:25 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/19 03:58:33 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->getName() << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(void)
	: ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name)
	: ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap " << this->getName() << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
	: ClapTrap(obj.getName())
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	this->setName(obj.getName());
	this->setHitPoints(obj.getHitPoints());
	this->setEnergyPoints(obj.getEnergyPoints());
	this->setAttackDamage(obj.getAttackDamage());
	return (*this);
}

/* ************************************************************************** */
// get/set
/* ************************************************************************** */

/* ************************************************************************** */
// etc
/* ************************************************************************** */

void	ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " can not attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::guardGate(void)
{
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " can not guard gate" << std::endl;
		return ;
	}
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
