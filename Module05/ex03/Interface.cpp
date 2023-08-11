/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:05:57 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/12 03:35:02 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Interface.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

Interface::~Interface(void)
{
	for (size_t i = 0; i < MAX_FORM; i++)
		delete _forms[i];
}

Interface::Interface(void)
	: _bureaucrat("minjungk", 42)
{
	_end = false;
	_idx = 0;
	for (size_t i = 0; i < MAX_FORM; i++)
		_forms[i] = NULL;
}

Interface::Interface(std::string bureaucrat)
	: _bureaucrat(bureaucrat, 42)
{
	_end = false;
	_idx = 0;
	for (size_t i = 0; i < MAX_FORM; i++)
		_forms[i] = NULL;
}

Interface::Interface(const Interface& obj)
{
	*this = obj;
}

Interface& Interface::operator=(const Interface& obj)
{
	if (this == &obj)
		return (*this);
	_idx = obj._idx;
	for (size_t i = 0; i < MAX_FORM; i++)
		_forms[i] = obj._forms[i]? obj._forms[i]->clone() : NULL;
	return (*this);
}

/* ************************************************************************** */
// gui
/* ************************************************************************** */

void	Interface::run(void)
{
	while (_end == false)
	{
		_display();
		_moveCursor(5 + _idx, 2);
		_command();
	}
}

void	Interface::_display(void) const
{
	std::cout << CLEAR_SCREEN;
	std::cout << this->_bureaucrat << std::endl;
	std::cout << "╔══════════════════════════════════════════════════════════════════════════════╗" << std::endl;

	std::cout << "\033[1m"
		<< "║"
		<< std::setw(3) << " "
		<< "│"
		<< std::setw(7) << "Sign." 
		<< "│"
		<< std::setw(7) << "Exec." 
		<< "│"
		<< std::setw(30) << "Form Name" 
		<< "│"
		<< std::setw(27) << "Form Target" 
		<< "║"
		<< "\033[0m" << std::endl;

	std::cout << "║───┼───────┼───────┼──────────────────────────────┼───────────────────────────║" << std::endl;
	for (size_t i = 0; i < MAX_FORM; i++)
	{
		if (_forms[i])
			std::cout << *_forms[i] << std::endl;
		else
			std::cout << "║   |       |       |                              |                           ║" << std::endl;
	}
	std::cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << std::endl;
}

void	Interface::_moveCursor(int row, int col) const
{
	std::cout << "\x1b[" << row << ";" << col << "H";
}

void	Interface::_commandForm(void)
{
	if (_forms[_idx] == NULL)
	{
		_moveCursor(16, 0);
		_newForm();
		return ;
	}
	int	selected = 0;
	while (1)
	{
		static const char *popup[5] = 
		{
			"┌───────────────────────────┐",
			"│       Choose option       │",
			"│                           │",
			"│ [sign] [execute] [delete] │",
			"└───────────────────────────┘"
		};
		for (int i = 0; i < 5; i++)
		{
			_moveCursor(8 + i, 20);
			switch (i)
			{
				case 1:
					std::cout << "\033[1m" << popup[i] << "\033[0m" << std::endl;
					break ;
				case 3:
				{
					switch (selected)
					{
						case 0:
							std::cout << "│ \033[44m[sign]\033[0m [execute] [delete] │" << std::endl;
							_moveCursor(8 + i, 20 + 2);
							break ;
						case 1:
							std::cout << "│ [sign] \033[44m[execute]\033[0m [delete] │",
							_moveCursor(8 + i, 20 + 11);
							break ;
						case 2:
							std::cout << "│ [sign] [execute] \033[44m[delete]\033[0m │",
							_moveCursor(8 + i, 20 + 21);
							break ;
					}
					break ;
				}
				default:
					std::cout << popup[i] << std::endl; 
			}
		}
		int	key = getchar();
		
		switch (key)
		{
			case 'q':
				return ;
			case 's': selected = 0; break ;
			case 'e': selected = 1; break ;
			case 'd': selected = 2; break ;
			case '\033':
					getchar();
					key = getchar();
					switch (key)
					{
						case 'C': // Arrow Right
							selected = (selected + 1) % 3;
							break ;
						case 'D': // Arrow Down
							selected = (3 + selected - 1) % 3;
							break ;
					}
					break ;
				case '\n':
					_display();
					_moveCursor(16, 0);
					switch (selected)
					{
						case 0:
							_bureaucrat.signForm(*_forms[_idx]);
							getchar();
							break ;
						case 1:
							_bureaucrat.executeForm(*_forms[_idx]);
							getchar();
							break ;
						case 2:
							delete _forms[_idx];
							_forms[_idx] = NULL;
							break ;
					}
					return ;
			}
		}
}

void	Interface::_command(void)
{
	struct termios	old_term;

	tcgetattr(STDIN_FILENO, &old_term);
	{
		struct termios	new_term = old_term;
		new_term.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
		{
			int	key = getchar();
			
			switch (key)
			{
				case 'q':
					_end = true;
					_moveCursor(16, 0);
					break ;
				case '1': _bureaucrat.decrement(); break ;
				case '2': _bureaucrat.increment(); break ;
				case '\033':
					getchar();
					key = getchar();
					switch (key)
					{
						case 'A': // Arrow Up
							_idx = (MAX_FORM + _idx - 1) % MAX_FORM;
							break ;
						case 'B': // Arrow Down
							_idx = (_idx + 1) % MAX_FORM;
							break ;
					}
					break ;
				case '\n':
					_commandForm();
					break ;
				default:
					break ;
			}
		}
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
}

/* ************************************************************************** */
// backend
/* ************************************************************************** */

AForm*	Interface::_newForm(void)
{
	std::string	name;
	std::string	target;
	AForm*		form;

	try
	{
		Intern	intern;
		{
			for (int i = 0; i < Intern::MAX_FORM_TYPE; i++)
				std::cout << i << ": " << intern.getFormName(i) << std::endl;
			int	selected;
			while (1)
			{
				std::cout << "select name: ";
				std::cin >> selected;
				if (std::cin.eof() || std::cin.fail())
					std::cout << "\033[K";
				else
					break ;
			}
			name = intern.getFormName(selected);
		}
		{
			while (1)
			{
				std::cout << "input target: ";
				std::cin >> target;
				if (std::cin.eof() || std::cin.fail())
					std::cout << "\033[K";
				else
					break ;
			}
		}
		form = intern.makeForm(name, target);
	}
	catch (std::exception &e)
	{
		std::cout << "failed to newForm: " << e.what() << std::endl;
		return (NULL);
	}
	for (size_t i = 0; i < MAX_FORM; i++)
	{
		if (this->_forms[i] == NULL)
		{
			this->_forms[i] = form;
			return (form);
		}
	}
	return (form);
}
