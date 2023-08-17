/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:17:35 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/18 03:32:25 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void)
{
	Base*	base;

	std::srand(std::time(NULL));
	for (int i = 0; i < 42; i++)
	{
		base = generate();
		identify(base);
		delete base;
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
