/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:05:57 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/12 18:45:28 by minjungk         ###   ########.fr       */
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
// util
/* ************************************************************************** */

void	Interface::_moveCursor(int row, int col) const
{
	std::cout << "\x1b[" << row << ";" << col << "H";
}

int	Interface::_getKey(void) const
{
	int				key;
	struct termios	old_term, new_term;

	tcgetattr(STDIN_FILENO, &old_term);
	{
		new_term = old_term;
		new_term.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW, &new_term);
		key = getchar();
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
	return (key);
}

/* ************************************************************************** */
// display
/* ************************************************************************** */

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

void	Interface::_displayOption(int selected) const
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
				switch (selected)
				{
					case 0:
						std::cout << "│ \033[44m[sign]\033[0m [execute] [delete] │" << std::endl;
						_moveCursor(8 + i, 20 + 2);
						break ;
					case 1:
						std::cout << "│ [sign] \033[44m[execute]\033[0m [delete] │" << std::endl;
						_moveCursor(8 + i, 20 + 11);
						break ;
					case 2:
						std::cout << "│ [sign] [execute] \033[44m[delete]\033[0m │" << std::endl;
						_moveCursor(8 + i, 20 + 21);
						break ;
				}
				break ;
			default:
				std::cout << popup[i] << std::endl; 
		}
	}
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
		switch (_getKey())
		{
			case 'q':
				_end = true;
				_moveCursor(16, 0);
				break ;
			case '1':
				_bureaucrat.decrement();
				break ;
			case '2':
				_bureaucrat.increment();
				break ;
			case '\033':
				_getKey();	// skip '['
				switch (_getKey())
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
				_commandOption();
				break ;
		}
	}
}

void	Interface::_commandOption(void)
{
	if (_forms[_idx] == NULL)
	{
		_moveCursor(16, 0);
		_newForm();
		_getKey();	// press any key
		return ;
	}
	int	selected = 0;
	while (1)
	{
		_displayOption(selected);
		switch (_getKey())
		{
			case 'q':
				return ;
			case 's':
				selected = 0;
				break ;
			case 'e':
				selected = 1;
				break ;
			case 'd':
				selected = 2;
				break ;
			case '\033':
				_getKey();
				switch (_getKey())
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
						_getKey();	// press any key
						break ;
					case 1:
						_bureaucrat.executeForm(*_forms[_idx]);
						_getKey();	// press any key
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

void	Interface::_newForm(void)
{
	std::string	name;
	std::string	target;
	try
	{
		Intern	intern;
		{
			for (int i = 0; i < Intern::MAX_FORM_TYPE; i++)
				std::cout << i << ": " << intern.getFormName(i) << std::endl;
			int	selected = 4;
			while (1)
			{
				std::cout << "select name number: ";
				std::cin >> selected;
				if (0 <= selected && selected < Intern::MAX_FORM_TYPE)
					break ;
				if (std::cin.eof() || std::cin.fail())
					throw std::invalid_argument("name error");
				std::cout << MOVE_CURSOR_UP << CLEAR_LINE;
			}
			name = intern.getFormName(selected);
		}
		{
			std::cout << "input target: ";
			std::cin >> target;
			if (std::cin.eof() || std::cin.fail())
				throw std::invalid_argument("target error");
		}
		this->_forms[_idx] = intern.makeForm(name, target);
		_display();
		_moveCursor(16, 0);
		std::cout << "intern makes Form(\"" << name << "\", \"" << target << "\")" << std::endl;
	}
	catch (std::exception &e)
	{
		_display();
		_moveCursor(16, 0);
		std::cout << "failed to newForm: " << e.what() << std::endl;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
