/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:02:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 02:46:17 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_H__
# define __CAT_H__
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*_brain;
	public:
		virtual ~Cat(void);
		Cat(void);
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
};

#endif /* __CAT_H__ */
