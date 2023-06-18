/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:14:41 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/19 03:55:53 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(void)
	:_hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name)
	:_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->_name = obj.getName();
	this->_hit_points = obj.getHitPoints();
	this->_energy_points = obj.getEnergyPoints();
	this->_attack_damage = obj.getAttackDamage();
	return (*this);
}

/* ************************************************************************** */
// get/set
/* ************************************************************************** */

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(unsigned int hit_points)
{
	this->_hit_points = hit_points;
}

void	ClapTrap::setEnergyPoints(unsigned int energy_points)
{
	this->_energy_points = energy_points;
}

void	ClapTrap::setAttackDamage(unsigned int attack_damage)
{
	this->_attack_damage = attack_damage;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hit_points);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energy_points);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attack_damage);
}

/* ************************************************************************** */
// etc
/* ************************************************************************** */

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points <= 0 || this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can not attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has already been defeated" << std::endl;
		return ;
	}
	if (this->_hit_points < amount)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " is attacked and has " << this->_hit_points << " hit points remaning" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is not repairable" << std::endl;
		return ;
	}
	this->_hit_points += amount;
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " repaired and became a " << this->_hit_points << std::endl;
}
