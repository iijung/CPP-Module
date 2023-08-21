/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:11:03 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/21 22:07:26 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Interface.hpp"

int	main(int argc, char **argv)
{
	if (!isatty(STDIN_FILENO))
	{
		std::cerr << "Please use termial" << std::endl;
		return (EXIT_FAILURE);
	}
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <name>" << std::endl;
		return (EXIT_SUCCESS);
	}
	Interface	interface(argv[1]);

	interface.run();
	return (0);
}
