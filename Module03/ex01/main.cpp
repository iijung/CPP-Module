/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:26:00 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/19 06:14:12 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void	test00(void)
{
	ClapTrap	clap("Cla");

	std::cout << "---------------- PROFILE -----------------" << std::endl;
	std::cout << "Name: " << clap.getName() << std::endl;
	std::cout << "HitPoints(10): " << clap.getHitPoints() << std::endl;
	std::cout << "EnergyPoints(10): " << clap.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage(0): " << clap.getAttackDamage() << std::endl;
	std::cout << "----------------- Attack -----------------" << std::endl;
	clap.attack("self");
	std::cout << "----------------- Damage -----------------" << std::endl;
	clap.takeDamage(clap.getAttackDamage());
	std::cout << "----------------- Repair -----------------" << std::endl;
	clap.beRepaired(5);
	std::cout << "------------------------------------------" << std::endl;
}

static void	test01(void)
{
	ClapTrap	*p[2];
	ClapTrap	clap("Cla");
	ScavTrap	scav("Sca");

	p[0] = &clap;
	p[1] = &scav;
	std::cout << "---------------- PROFILE -----------------" << std::endl;
	std::cout << "Name: " << scav.getName() << std::endl;
	std::cout << "HitPoints(100): " << scav.getHitPoints() << std::endl;
	std::cout << "EnergyPoints(50): " << scav.getEnergyPoints() << std::endl;
	std::cout << "AttackDamage(20): " << scav.getAttackDamage() << std::endl;
	std::cout << "----------------- Attack -----------------" << std::endl;
	p[0]->attack("clap self");
	p[1]->attack("scav self");
	std::cout << "----------------- Damage -----------------" << std::endl;
	p[0]->takeDamage(p[0]->getAttackDamage());
	p[1]->takeDamage(p[1]->getAttackDamage());
	std::cout << "----------------- Repair -----------------" << std::endl;
	p[0]->beRepaired(5);
	p[1]->beRepaired(5);
	std::cout << "----------------- Guard ------------------" << std::endl;
	scav.guardGate();
	std::cout << "------------------------------------------" << std::endl;
}

int	main(void)
{
	int	num;

	std::cin >> num;
	switch (num)
	{
		case 0:	test00(); break;
		case 1:	test01(); break;
	}
	return (0);
}
