/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:55:15 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/24 02:09:00 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>	// cout
#include <iomanip>	// setw, setfill

void	test_throw(Span &sp)
{
	try
	{
		sp.addNumber(42);
		std::cout << "failed to throw" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test_many(void)
{
	Span	sp(10000);

	sp.addManyNumber();

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::setw(80) << std::setfill('=') << "=" << std::endl;
	test_throw(sp);
	std::cout << std::setw(80) << std::setfill('=') << "=" << std::endl;
	test_many();
	return 0;
}
