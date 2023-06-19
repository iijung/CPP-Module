/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:09:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 01:54:02 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->_type = obj.getType();
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->_type << " is crying" << std::endl;
}
