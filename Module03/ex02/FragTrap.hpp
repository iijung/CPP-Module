/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:23:13 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/19 03:59:15 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FRAG_TRAP_H__
# define __FRAG_TRAP_H__
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
	public:
		virtual ~FragTrap(void);
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap& target);
		FragTrap&	operator=(const FragTrap& obj);

		void	highFivesGuys(void);
};

#endif /* __FRAG_TRAP_H__ */
