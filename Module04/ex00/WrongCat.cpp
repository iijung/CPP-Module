/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:11:47 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 01:56:37 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(void): WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj): WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->_type = obj.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->_type << " don't bark" << std::endl;
}
