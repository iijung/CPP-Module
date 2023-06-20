/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 05:58:26 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 03:56:51 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CURE_H__
# define __CURE_H__
# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& obj);
		Cure& operator=(const Cure& obj);
		virtual ~Cure(void);

		Cure*	clone() const;
		void	use(ICharacter& target);
};

#endif /* __CURE_H__ */
