/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:05:02 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/19 06:21:25 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(void):
	ClapTrap(), ScavTrap(), FragTrap(), _name(NULL)
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->setEnergyPoints(50);
}

DiamondTrap::DiamondTrap(const std::string name):
	ClapTrap(), ScavTrap(), FragTrap(), _name(name)
{
	ClapTrap::setName(std::string(name).append(std::string("_clap_name")));
	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
	this->setEnergyPoints(50);
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj):
	ClapTrap(obj),
	ScavTrap(obj),
	FragTrap(obj)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = obj;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& obj)
{
	this->_name = obj.getName();
	this->setName(obj.getName().append(std::string("_clap_name")));
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
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

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap " << this->_name << " and " << this->getName() << std::endl;
}
