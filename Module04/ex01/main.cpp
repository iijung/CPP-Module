/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.82seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:05:87 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 05:32:36 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define MAX	4

static void	test_array(void)
{
	Animal*		arr[MAX];

	for (int idx = 0; idx < MAX; idx++)
	{
		if (idx % 2 == 0)
			arr[idx] = new Dog();
		else
			arr[idx] = new Cat();
	}
	std::cout << "-----------------------------------------------" << std::endl;
	for (int idx = 0; idx < MAX; idx++)
		delete arr[idx];
}

static void	test_copy(void)
{
	Cat	cat1;
	Cat	cat2(cat1);
	std::cout << "-------------------------------------------" << std::endl;
	cat1.getBrain()->fill("meow");
	cat1.getBrain()->show();
	cat2.getBrain()->show();
	std::cout << "-------------------------------------------" << std::endl;
	cat2.getBrain()->fill("miaow");
	cat1.getBrain()->show();
	cat2.getBrain()->show();
	std::cout << "-------------------------------------------" << std::endl;
}

int main() 
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	delete j;
	delete i;
	std::cout << "# Array #######################################" << std::endl;
	test_array();
	std::cout << "# Deep Copy ###################################" << std::endl;
	test_copy();
	return 0;
}
