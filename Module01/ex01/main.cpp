/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 03:00:11 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 15:45:42 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

static void	test(int N, std::string name)
{
	Zombie	*horde;

	horde = zombieHorde(N, name);
	for (int i = 0; i < N; ++i)
		horde[i].announce();
	delete[] horde;
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <N> <name>" << std::endl;
		return (EXIT_FAILURE);
	}
	test(std::atoi(argv[1]), std::string(argv[2]));
	return (EXIT_SUCCESS);
}
