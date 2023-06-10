/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:20:17 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/10 18:26:57 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "address of the string: " << &string << std::endl;
	std::cout << "address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "address held by stringEFR: " << &stringREF << std::endl;

	std::cout << "value of the string: " << string << std::endl;
	std::cout << "value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "value of the stringREF: " << stringREF << std::endl;
	
	return (EXIT_SUCCESS);
}
