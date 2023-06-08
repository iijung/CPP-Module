/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 02:52:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 03:34:09 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
	: _name("Walker")
{
	std::cout << this->_name << " created." << std::endl;
}

Zombie::Zombie(std::string name)
	: _name(name)
{
	std::cout << this->_name << " created." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " destroyed." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
