/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 05:58:27 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 03:46:12 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ICE_H__
# define __ICE_H__
# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& obj);
		Ice& operator=(const Ice& obj);
		virtual ~Ice(void);

		Ice* 	clone() const;
		void 	use(ICharacter& target);
};

#endif /* __ICE_H__ */
