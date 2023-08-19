/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:39:52 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/20 03:01:05 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_H__
# define __ARRAY_H__
# include <stdexcept>
# include <cstdlib>

template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T*				_arr;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &obj);
		Array& operator=(Array const &obj);
		virtual ~Array(void);

		unsigned int	size(void) const;
		T&				operator[](unsigned int n);
		const T&		operator[](unsigned int n) const;
};

template <typename T>
std::ostream&	operator<<(std::ostream &out, const Array<T> &obj);

# include "Array.tpp"

#endif /* __ARRAY_H__ */
