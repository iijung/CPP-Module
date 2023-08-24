/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:50:26 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/24 02:08:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SPAN_H__
# define __SPAN_H__
# include <vector>
# include <ctime>		// time
# include <numeric>		// adjacent_difference
# include <algorithm>	// copy, rand, srand, generate_n, transform, *_element
# include <stdexcept>	// runtime_error

class	Span
{
	private:
		
		unsigned int		_size;
		std::vector<int>	_numbers;

		Span(void);
	public:
		Span(unsigned int n);
		Span(const Span &obj);
		Span& operator=(const Span &obj);
		virtual ~Span(void);

		void	addNumber(int num);
		void	addManyNumber(void);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
};

#endif /* __SPAN_H__ */
