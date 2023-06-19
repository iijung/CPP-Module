/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:02:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 01:55:08 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WRONG_CAT_H__
# define __WRONG_CAT_H__
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		virtual ~WrongCat(void);
		WrongCat(void);
		WrongCat(const WrongCat& obj);
		WrongCat& operator=(const WrongCat& obj);

		void	makeSound(void) const;
};

#endif /* __WRONG_CAT_H__ */
