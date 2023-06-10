/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 06:09:17 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/11 06:49:38 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	complain;

	while (1)
	{
		std::cin >> complain;
		if (std::cin.eof())
			break ;
		harl.complain(complain);
	}
	return (EXIT_SUCCESS);
}
