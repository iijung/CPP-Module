/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:14:20 by minjungk          #+#    #+#             */
/*   Updated: 2023/05/26 01:32:51 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	displayUpperCase(const std::string& str)
{
	for (std::string::size_type i = 0; i < str.length(); ++i)
		std::cout << char(std::toupper(str[i]));
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
		displayUpperCase(argv[i]);
	std::cout << std::endl;
	return (0);
}
