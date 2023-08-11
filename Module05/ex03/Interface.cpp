/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:05:57 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/12 00:18:58 by minjungk         ###   ########.fr       */
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
		_command();
	}
}

void	Interface::_display(void)
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
			std::cout << _forms[i] << std::endl;
		else
			std::cout << "║   |       |       |                              |                           ║" << std::endl;
	}
	std::cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << std::endl;
}

void	Interface::_commandForm(void)
{
	int	row = 4;
	int	col = 3;
	std::cout << "\x1b[" << row << ";" << col << "H";
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
				case 'q': _end = true; break ;
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

AForm*	Interface::newForm(void)
{
	std::string	name;
	std::string	target;
	AForm*		form;

	try
	{
		Intern	intern;
		{
			for (int i = 0; i < Intern::MAX_FORM_TYPE; i++)
				std::cout << i << ": " << intern.getFormName(static_cast<Intern::e_form_type>(i)) << std::endl;
			std::cout << "select name: ";
			int	selected;
			std::cin >> selected;
			name = intern.getFormName(static_cast<Intern::e_form_type>(selected));
		}
		{
			std::cout << "input target: ";
			std::cin >> target;
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

void	Interface::deleteForm(void)
{
	delete this->_forms[_idx];
	this->_forms[_idx] = NULL;
}
