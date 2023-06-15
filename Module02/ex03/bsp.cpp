/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:22:35 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/15 15:09:39 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	_area(Point const a, Point const b, Point const c)
{
	float	size;
	
	size = a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY();
	size -= a.getX() * c.getY() + c.getX() * b.getY() + b.getX() * a.getY();
	size /= 2;
	return (size > 0? size: -size);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	area[4];

	area[0] = _area(a, b, c);
	area[1] = _area(a, b, point);
	area[2] = _area(a, point, c);
	area[3] = _area(point, b, c);
	if (area[1] == 0 || area[2] == 0 || area[3] == 0)
		return (false);
	return (area[0] == area[1] + area[2] + area[3]);
}
