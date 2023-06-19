/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:02:39 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 03:50:19 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DOG_H__
# define __DOG_H__
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*_brain;
	public:
		virtual ~Dog(void);
		Dog(void);
		Dog(const Dog& obj);
		Dog& operator=(const Dog& obj);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
};

#endif /* __DOG_H__ */
