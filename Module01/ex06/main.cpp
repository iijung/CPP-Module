/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 06:09:17 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/11 08:31:22 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);
	Harl().complain(std::string(argv[1]));
	return (EXIT_SUCCESS);
}
