/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:05:06 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/19 05:17:41 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DIAMOND_TRAP_H__
# define __DIAMOND_TRAP_H__
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		virtual ~DiamondTrap(void);
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap& target);
		DiamondTrap&	operator=(const DiamondTrap& obj);

		void	whoAmI(void);
};

#endif /* __DIAMOND_TRAP_H__ */
