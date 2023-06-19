/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:02:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 01:36:49 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_H__
# define __CAT_H__
# include "Animal.hpp"

class Cat: public Animal
{
	public:
		virtual ~Cat(void);
		Cat(void);
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);

		void	makeSound(void) const;
};

#endif /* __CAT_H__ */
