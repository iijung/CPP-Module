/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 00:59:31 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/19 01:07:43 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_H__
# define __WHATEVER_H__

template <typename T>
void	swap(T & a, T & b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>
T const &	min(T const & a, T const & b) { return a < b? a : b; }

template <typename T>
T const &	max(T const & a, T const & b) { return a > b? a : b; }

#endif /* __WHATEVER_H__ */
