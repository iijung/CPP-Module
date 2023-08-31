/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:38:03 by minjungk          #+#    #+#             */
/*   Updated: 2023/09/01 00:26:28 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " ..." << std::endl;
		return (EXIT_FAILURE);
	}
	std::vector<uint32_t>	o;
	std::vector<uint32_t>	v;
	std::deque<uint32_t>	d;
	try
	{
		o = make(argc - 1, argv + 1);
		v.assign(o.begin(), o.end());
		d.assign(o.begin(), o.end());

		std::cout << "Before: "; show(o); std::cout << std::endl;
		double elapsed_v	= sort(v);
		double elapsed_d	= sort(d);
		std::cout << "After : "; show(d); std::cout << std::endl;

		std::cout << std::fixed
			<< "Time to process a range of " << d.size()
			<< " elements with std::vector : " << elapsed_v
			<< " us" << std::endl;
		std::cout << std::fixed
			<< "Time to process a range of " << d.size()
			<< " elements with std::deque  : " << elapsed_d
			<< " us" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
