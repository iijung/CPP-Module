/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:12:16 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/14 17:16:53 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __POINT_H__
# define __POINT_H__
# include "Fixed.hpp"

class Point
{
	private:
		Fixed	_x;
		Fixed	_y;
	public:
		Point(void);
		Point(float const a, float const b);
		Point(const Point &obj);
		~Point(void);

		Point&	operator=(const Point &obj);

		float	getX(void) const;
		float	getY(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Point& obj);

bool	bsp(Point const a, Point const b, Point const c, Point const point);
#endif /* __POINT_H__ */
