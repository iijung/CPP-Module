/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.82seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:05:87 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 05:43:40 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	delete j;
	delete i;
	return 0;
}
