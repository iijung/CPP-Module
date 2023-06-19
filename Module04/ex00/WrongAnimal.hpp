/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:01:16 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 01:55:20 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONG_ANIMAL_H__
# define __WRONG_ANIMAL_H__
# include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		virtual ~WrongAnimal(void);
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal& operator=(const WrongAnimal& obj);

		std::string		getType(void) const;
		void			makeSound(void) const;
};

#endif /* __WRONG_ANIMAL_H__ */
