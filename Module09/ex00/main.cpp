/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:46:57 by minjungk          #+#    #+#             */
/*   Updated: 2023/09/01 17:15:04 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	(void)argc;
	try
	{
		BitcoinExchange	btc("data.csv");

		btc.run(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
