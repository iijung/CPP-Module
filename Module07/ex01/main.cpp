/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:16:07 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/19 01:23:02 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	test_int(void)
{
	int	arr[] = {1, 2, 3, 4};

	std::cout << "Int: ";
	iter(arr, sizeof(arr) / sizeof(int), print);
	std::cout << std::endl;
}

void	test_float(void)
{
	float	arr[] = {1.1, 2.2, 3.3, 4.4};

	std::cout << "Float: ";
	iter(arr, sizeof(arr) / sizeof(float), print);
	std::cout << std::endl;
}

void	test_char(void)
{
	char	arr[] = {'h', 'e', 'l', 'l', 'o'};

	std::cout << "Char: ";
	iter(arr, sizeof(arr) / sizeof(char), print);
	std::cout << std::endl;
}

int	main(void)
{
	test_int();
	test_float();
	test_char();
	return 0;
}
