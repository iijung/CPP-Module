/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 02:40:11 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 04:19:16 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain&	Brain::operator=(const Brain& obj)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = obj.getIdea(i);
	return (*this);
}

std::string	Brain::getIdea(int idx) const
{
	return (this->_ideas[idx]);
}

void	Brain::setIdea(int idx, const std::string idea)
{
	this->_ideas[idx] = idea;
}

void	Brain::fill(const std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = idea;
}

void	Brain::show(void) const
{
	for (int i = 0; i < 100; i++)
	{
		std::cout << std::setw(10) << this->_ideas[i];
		if (i % 10 == 9)
			std::cout << std::endl;
		else
			std::cout << " ";
	}
}
