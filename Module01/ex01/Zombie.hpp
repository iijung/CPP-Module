/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 02:47:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 15:53:43 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include <iostream>

class Zombie
{
	private:
		std::string	_name;
	public:
		~Zombie(void);
		Zombie(void);
		Zombie(std::string name);

		void	announce(void);
};

Zombie	*zombieHorde(int N, std::string name);

#endif /* __ZOMBIE_H__ */
