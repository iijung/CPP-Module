/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 05:56:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 04:04:12 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __A_MATERIA_H__
# define __A_MATERIA_H__
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(std::string const & type);
		AMateria(void);
		AMateria(const AMateria& obj);
		AMateria& operator=(const AMateria& obj);
		virtual ~AMateria(void);

		std::string const &	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif /* __A_MATERIA_H__ */
