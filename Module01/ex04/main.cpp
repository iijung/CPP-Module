/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:16:09 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/11 04:56:51 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FileReplacer.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (EXIT_FAILURE);
	if (FileReplacer(argv[1]).run(argv[2], argv[3]) != EXIT_SUCCESS)
	{
		std::cerr << "Error occur" << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << "Success" << std::endl;
	return (EXIT_SUCCESS);
}
