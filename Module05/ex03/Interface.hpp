/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:48:12 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/13 16:21:13 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __A_INTERFACE_H__
# define __A_INTERFACE_H__
# include "Intern.hpp"
# include <cstdio>
# include <unistd.h>
# include <termios.h>
# include <limits>

#define CLEAR_SCREEN	"\033[2J\033[H"
#define CLEAR_LINE		"\033[K"
#define MOVE_CURSOR_UP	"\033[A"
#define MOVE_CURSOR_DOWN "\033[B"

class Interface
{
	private:
		static const int	MAX_FORM = 10;

		Bureaucrat	_bureaucrat;
		AForm*		_forms[MAX_FORM];

		/* gui data*/
		bool		_end;
		size_t		_idx;

		/* gui util*/
		int		_getKey(void) const;
		void	_moveCursor(int row, int col) const;
		void	_display(void) const;
		void	_displayOption(int selected) const;
		void	_commandOption(void);

		/* util*/
		void	_newForm(void);
	public:
		Interface(void);
		Interface(std::string bureaucrat);
		Interface(const Interface& obj);
		Interface& operator=(const Interface& obj);
		virtual ~Interface(void);

		void	run(void);
};

#endif /* __A_INTERFACEH__ */
