/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 06:03:53 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/21 04:37:44 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iomanip>

int main()
{
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter*	bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::setfill('=') << std::setw(80) << "=" << std::endl;
	{
		ICharacter	*min = new Character("min");
		ICharacter	*jung = new Character("jung");
		AMateria	*arr[4] = {new Ice(), new Ice(), new Ice(), new Ice()};
		for (int i = 0; i < 4; i++)
			min->equip(arr[i]);
		std::cout << std::setfill('-') << std::setw(80) << "min->use" << std::endl;
		for (int i = 0; i < 4; i++)
			min->use(i, *jung);
		std::cout << std::setfill('-') << std::setw(80) << "min->uneqip / jung->equip / jung->use" << std::endl;
		min->unequip(2);
		jung->equip(arr[2]);
		for (int i = 0; i < 4; i++)
			jung->use(i, *min);
		std::cout << std::setfill('-') << std::setw(80) << "min->equip" << std::endl;
		min->equip(new Cure());
		std::cout << std::setfill('-') << std::setw(80) << "min->use" << std::endl;
		for (int i = 0; i < 4; i++)
			min->use(i, *jung);
		std::cout << std::setfill('-') << std::setw(80) << "-" << std::endl;
		delete min;
		delete jung;
	}
	return 0;
}
