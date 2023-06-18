/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:54:20 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/19 03:59:19 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAV_TRAP_H__
# define __SCAV_TRAP_H__
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
	public:
		virtual ~ScavTrap(void);
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap& target);
		ScavTrap&	operator=(const ScavTrap& obj);

		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif /* __SCAV_TRAP_H__ */
