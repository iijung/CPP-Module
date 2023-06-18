/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:23:11 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/19 06:22:41 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->getName() << " destructor called" << std::endl;
}

FragTrap::FragTrap(void)
	: ClapTrap()
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name)
	: ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap " << this->getName() << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
	: ClapTrap(obj.getName())
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = obj;
}

FragTrap&	FragTrap::operator=(const FragTrap& obj)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
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

void	FragTrap::highFivesGuys(void)
{
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " can not high fives" << std::endl;
		return ;
	}
	std::cout << "FragTrap high fives!" << std::endl;
}
