/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:26:00 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/19 06:13:47 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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

int	main(void)
{
	int	num;

	std::cin >> num;
	switch (num)
	{
		case 0:	test00(); break;
	}
	return (0);
}
