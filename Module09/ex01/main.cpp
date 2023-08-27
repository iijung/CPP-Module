/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:19:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/27 17:21:22 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <polish mathematical expression>" << std::endl;
		return (EXIT_FAILURE);
	}
	RPN::run(argv[1]);
	return (EXIT_SUCCESS);
}
