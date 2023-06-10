/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 05:01:56 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/11 06:44:49 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HARL_H__
# define __HARL_H__
# include <iostream>

class	Harl
{
	private:
		void	(Harl::*_f)(void);

		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
	public:
		Harl(void);
		~Harl(void);

		enum Level
		{
			LEVEL_NONE = 0,
			LEVEL_DEBUG,
			LEVEL_INFO,
			LEVEL_WARNING,
			LEVEL_ERROR,
			MAX_LEVEL
		};

		Level	getLevel(std::string level);
		void	complain(std::string level);
};

#endif /* __HARL_H__ */
