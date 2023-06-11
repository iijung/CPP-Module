/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:12:25 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/12 00:00:24 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_H__
# define __FIXED_H__
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_raw;
		static const int	_bits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &obj);
		Fixed(int const raw);
		Fixed(float const raw);

		Fixed&	operator=(const Fixed &obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;

		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
	
		static Fixed&		max(Fixed &obj1, Fixed &obj2);
		static Fixed&		min(Fixed &obj1, Fixed &obj2);
		static const Fixed&	max(const Fixed &obj1, const Fixed &obj2);
		static const Fixed&	min(const Fixed &obj1, const Fixed &obj2);

		friend std::ostream&	operator<<(std::ostream& out, const Fixed& obj);
};

#endif /* __FIXED_H__ */
