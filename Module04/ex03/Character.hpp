/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:16:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 04:03:18 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CHARACTER_H__
# define __CHARACTER_H__
# include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_slot[4];
	public:
		Character(void);
		Character(std::string name);
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		virtual ~Character(void);

		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

		AMateria*			getSlot(int idx) const;
};

#endif /* __CHARACTER_H__ */
