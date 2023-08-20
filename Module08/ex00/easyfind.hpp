/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:55:41 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/21 00:43:59 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASY_FIND_H__
# define __EASY_FIND_H__
# include <algorithm>	// find
# include <stdexcept>	// runtime_error

template <typename T>
typename T::iterator	easyfind(T& container, const int & value);

# include "easyfind.tpp"

#endif /* __EASY_FIND_H__ */
