/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:48:12 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/12 00:12:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __A_FORM_REPOSITORY_H__
# define __A_FORM_REPOSITORY_H__
# include "Intern.hpp"
# include <cstdio>
//# include <cstdlib>
# include <unistd.h>
# include <termios.h>

#define CLEAR_SCREEN "\x1b[2J\x1b[H"
#define HIDE_CURSOR "\x1b[?25l"
#define SHOW_CURSOR "\x1b[?25h"
#define MOVE_CURSOR_UP "\x1b[A"
#define MOVE_CURSOR_DOWN "\x1b[B"

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
		void		moveCursorTo(int row, int col) {
			std::cout << "\x1b[" << row << ";" << col << "H";
		}

		AForm*	newForm(void);
		void	deleteForm(void);

		void	_display(void);
		void	_commandForm(void);
		void	_command(void);
	public:
		Interface(void);
		Interface(std::string bureaucrat);
		Interface(const Interface& obj);
		Interface& operator=(const Interface& obj);
		virtual ~Interface(void);

		void	run(void);
};

#endif /* __A_FORM_REPOSITORYH__ */
