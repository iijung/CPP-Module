/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:55:15 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/23 18:10:13 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <iostream>

void	print(const int & n)
{
	std::cout << n << ' ';
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <value>" << std::endl;
		return 1;
	}
	int							value = std::atoi(argv[1]);
	std::vector<int>			v;
	std::deque<int>				d;
	std::list<int>				l;

	for (int i = 0; i < 5; i++)
	{
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}

	try
	{
		std::vector<int>::iterator				it = easyfind(v, value);
		std::cout << "vector: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "vector: " << e.what() << std::endl;
	}
	try
	{
		std::deque<int>::iterator				it = easyfind(d, value);
		std::cout << "deque: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "deque: " << e.what() << std::endl;
	}
	try
	{
		std::list<int>::iterator				it = easyfind(l, value);
		std::cout << "list: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "list: " << e.what() << std::endl;
	}
	return 0;
}
