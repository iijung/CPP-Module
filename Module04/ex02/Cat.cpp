/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:11:47 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 05:30:13 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(void): Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::Cat(const Cat& obj): Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj)
{
	Brain	*brain = obj.getBrain();

	std::cout << "Cat copy assignment operator called" << std::endl;
	this->_type = obj.getType();
	delete this->_brain;
	this->_brain = NULL;
	if (brain)
		this->_brain = new Brain(*brain);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type << " don't bark" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
}
