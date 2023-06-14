/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:03:33 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/14 14:44:43 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;;
}

void	Harl::_warning(void)
{
	std::cerr << "[ WARNING ]" << std::endl;
	std::cerr << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;;
}

void	Harl::_error(void)
{
	std::cerr << "[ ERROR ]" << std::endl;
	std::cerr << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

Harl::Level Harl::getLevel(std::string level)
{
	static const std::string	type[] = {
		[LEVEL_NONE] = "NONE",
		[LEVEL_DEBUG] = "DEBUG",
		[LEVEL_INFO] = "INFO",
		[LEVEL_WARNING] = "WARNING",
		[LEVEL_ERROR] = "ERROR"
	};
	for (int i = 0; i < MAX_LEVEL; ++i)
	{
		if (level.compare(type[static_cast<Level>(i)]) == 0)
			return (static_cast<Level>(i));
	}
	return (LEVEL_NONE);
}

void	Harl::complain(std::string level)
{
	const enum Level	type = this->getLevel(level);

	switch (type)
	{
		case LEVEL_DEBUG:
			this->_debug();
			// fallthrough
		case LEVEL_INFO:
			this->_info();
			// fallthrough
		case LEVEL_WARNING:
			this->_warning();
			// fallthrough
		case LEVEL_ERROR:
			this->_error();
			break;
		default:
			std::cout <<  "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
