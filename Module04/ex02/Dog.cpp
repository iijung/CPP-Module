/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:11:48 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 22:28:29 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(void): Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

Dog::Dog(const Dog& obj): Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain;
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj)
{
	Brain	*brain = obj.getBrain();

	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this == &obj)
		return (*this);
	this->_type = obj.getType();
	delete this->_brain;
	this->_brain = NULL;
	if (brain)
		this->_brain = new Brain(*brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type << " barks" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}
