/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 00:11:09 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/21 00:11:54 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
typename T::iterator	easyfind(T& container, const int & value)
{
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Not found");
	return it;
}
