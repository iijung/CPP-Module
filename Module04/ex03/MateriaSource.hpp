/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:08:37 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 04:03:29 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MATERIA_SOURCE_H__
# define __MATERIA_SOURCE_H__
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_slot[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator=(const MateriaSource& obj);
		virtual ~MateriaSource(void);

		void		learnMateria(AMateria *m);
		AMateria*	createMateria(std::string const & type);
		AMateria*	getSlot(int idx) const;
};

#endif /* __MATERIA_SOURCE_H__ */
