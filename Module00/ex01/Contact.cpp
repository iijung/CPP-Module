/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 02:54:17 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/08 23:44:22 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::_showField(const std::string& str)
{
	if (str.length() <= 10)
		std::cout << std::setw(10) << str;
	else
		std::cout << str.substr(0, 9) << ".";
}

void	Contact::_setField(const std::string& hint, std::string& field)
{
	std::string::size_type	idx[2];

	while (1)
	{
		field.clear();
		std::cout << hint << " : ";
		std::getline(std::cin, field);
		if (std::cin.eof() || std::cin.fail())
			exit(EXIT_FAILURE);
		idx[0] = field.find_first_not_of(" \f\n\r\t\v");
		idx[1] = field.find_last_not_of(" \f\n\r\t\v");
		if (idx[0] != std::string::npos && idx[1] != std::string::npos)
		{
			field = field.substr(idx[0], idx[1] - idx[0] + 1);
			break ;
		}
	}
}

void	Contact::Set(void)
{
	this->_setField("first name", this->_first_name);
	this->_setField("last name", this->_last_name);
	this->_setField("nickname", this->_nickname);
	this->_setField("phone number", this->_phone_number);
	this->_setField("darkest secret", this->_darkest_secret);
}

void	Contact::Show(int index)
{
	std::cout << std::setw(10) << index;
	std::cout << " | ";
	this->_showField(this->_first_name);
	std::cout << " | ";
	this->_showField(this->_last_name);
	std::cout << " | ";
	this->_showField(this->_nickname);
	std::cout << std::endl;
}

void	Contact::ShowDetail(void)
{
	std::cout << "first name : " << this->_first_name << std::endl;
	std::cout << "last name : " << this->_last_name << std::endl;
	std::cout << "nickname : " << this->_nickname << std::endl;
	std::cout << "phone number: " << this->_phone_number << std::endl;
	std::cout << "darkest_secret : " << this->_darkest_secret << std::endl;
}
