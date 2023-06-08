/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 03:05:15 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/08 23:43:09 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _num(0), _idx(-1)
{
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::Add(void)
{
	this->_idx = (this->_idx + 1) % this->MAX_CONTACT;
	_contact[this->_idx].Set();
	if (this->_num < this->MAX_CONTACT)
		this->_num += 1;
}

void	PhoneBook::_Show(void)
{
	if (this->_num == 0)
	{
		std::cout << "Empty set" << std::endl;
		return ;
	}
	for (int i = 0; i < _num; ++i)
		_contact[i].Show(i);
	std::cout << _num << " rows in set" << std::endl;
}

void	PhoneBook::Search(void)
{
	int	index;

	while (1)
	{
		this->_Show();
		if (this->_num == 0)
			return ;
		std::cin >> index;
		if (std::cin.eof())
			exit(EXIT_FAILURE);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index" << std::endl;
			return ;
		}
		if (0 <= index && index < this->_num)
			_contact[index].ShowDetail();
		else
		{
			std::cout << "Invalid index" << std::endl;
			return ;
		}
	}
}
