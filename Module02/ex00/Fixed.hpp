/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:12:25 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/11 18:07:05 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_H__
# define __FIXED_H__
# include <iostream>

class Fixed
{
	private:
		int					_raw;
		static const int	_bits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &obj);

		Fixed&	operator=(const Fixed &obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif /* __FIXED_H__ */
