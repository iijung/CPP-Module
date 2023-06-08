/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 03:00:11 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 03:40:26 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	testStack(int argc, char **argv)
{
	for (int i = 0; i < argc; ++i)
		randomChump(std::string(argv[i]));
}

static void	testHeap(int argc, char **argv)
{
	Zombie	*arr[argc];

	for (int i = 0; i < argc; ++i)
		arr[i] = newZombie(std::string(argv[i]));
	for (int i = 0; i < argc; ++i)
		arr[i]->announce();
	for (int i = 0; i < argc; ++i)
		delete arr[i];
}

int	main(int argc, char **argv)
{
	std::cout << "========== STACK ==========" << std::endl;
	{
		testStack(argc - 1, argv + 1);
	}
	std::cout << "========== HEAP ===========" << std::endl;
	{
		testHeap(argc - 1, argv + 1);
	}
	return (0);
}
