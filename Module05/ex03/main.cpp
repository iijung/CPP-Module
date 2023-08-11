/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 23:11:03 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/11 17:08:02 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interface.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <name>" << std::endl;
		return (EXIT_SUCCESS);
	}
	Interface	interface(argv[1]);

	interface.run();
//	std::cout << std::setfill('=') << std::setw(80) << "=" << std::endl;
//	std::cout << std::setfill(' ') << repository;
//	std::cout << "q: Quit\t1:increment grade\t2:decrement grade" << std::endl;
//	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
//	std::cout << std::setfill('=') << std::setw(80) << "." << std::endl;
	return (0);
}
