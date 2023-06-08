/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungkminjungk@student.42se    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 03:06:59 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/08 23:40:33 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (1)
	{
		std::cout << "Usage: ADD | SEARCH" << std::endl;
		std::cin >> command;
		if (std::cin.eof() || std::cin.fail())
			return (EXIT_FAILURE);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (command.compare("EXIT") == 0)
			break ;
		else if (command.compare("ADD") == 0)
			phonebook.Add();
		else if (command.compare("SEARCH") == 0)
			phonebook.Search();
	}
	return (EXIT_SUCCESS);
}
