/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:38:13 by minjungk          #+#    #+#             */
/*   Updated: 2023/09/01 00:26:53 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __P_MERGE_ME_H__
# define __P_MERGE_ME_H__
# include <iostream>
# include <vector>
# include <deque>
# include <ctime>		// clock_t, clock, CLOCKS_PER_SEC
# include <stdint.h>	// uint32_t
# include <algorithm>	// lower_bound
# include <utility>		// pair

extern std::vector<uint32_t>	make(int argc, char **argv);
extern void						ford_johnson(std::vector<uint32_t>& arr);
extern void						ford_johnson(std::deque<uint32_t>& arr);

/* ************************************************************************** */
// template
/* ************************************************************************** */

template <typename T>
void	show(const T& container)
{
	typename T::const_iterator	it;

	for (it = container.begin(); it != container.end(); it++)
	{
		if (it != container.begin())
			std::cout << " ";
		std::cout << *it;
	}
}

template <typename T>
double	sort(T& container)
{
	clock_t	start_time = clock();
	{
		ford_johnson(container);
	}
	clock_t	end_time = clock();
	double	elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	return (elapsed_time);
}

#endif /* __P_MERGE_ME_H__ */
