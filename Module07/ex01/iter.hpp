/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:09:43 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/19 01:22:30 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_H__
# define __ITER_H__
# include <iostream>

template <typename T>
void	iter(T* arr, size_t len, void (*f)(T))
{
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void	print(T a)
{
	std::cout << a << " ";
}

#endif /* __ITER_H__ */
