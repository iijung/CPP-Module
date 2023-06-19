/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:01:16 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 00:59:20 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ANIMAL_H__
# define __ANIMAL_H__
# include <iostream>

class Animal
{
	protected:
		std::string	_type;
	public:
		virtual ~Animal(void);
		Animal(void);
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif /* __ANIMAL_H__ */
