/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:11:31 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/12 04:15:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Point.hpp"

static void	_test(float x = 6, float y = 7)
{
	Point	a(5, 4);
	Point	b(10, 8);
	Point	c(2, 11);
	Point	p(x, y);
	
	std::cout << "a" << a << std::endl;
	std::cout << "b" << b << std::endl;
	std::cout << "c" << c << std::endl;
	if (bsp(a, b, c, p))
		std::cout << "p" << p << " is inside" << std::endl;
	else
		std::cout << "p" << p << " is outside" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		_test();
	else
		_test(std::atof(argv[1]), std::atof(argv[2]));
	return (0);
}
