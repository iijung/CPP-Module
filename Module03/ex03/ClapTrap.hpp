/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:04:16 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/05 18:05:48 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAP_TRAP_H__
# define __CLAP_TRAP_H__
# include <iostream>

class	ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hit_points;
		unsigned int	_energy_points;
		unsigned int	_attack_damage;
	public:
		virtual	~ClapTrap(void);
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& target);
		ClapTrap&	operator=(const ClapTrap& obj);

		void	setName(std::string name);
		void	setHitPoints(unsigned int hit_points);
		void	setEnergyPoints(unsigned int energy_points);
		void	setAttackDamage(unsigned int attack_damage);

		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;

		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif /* __CLAP_TRAP_H__ */
