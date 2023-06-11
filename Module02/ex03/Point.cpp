/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 01:16:28 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/12 04:10:34 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::~Point(void)
{
}

Point::Point(void) : _x(0), _y(0)
{
}


Point::Point(float const a, float const b)
{
	this->_x = Fixed(a);
	this->_y = Fixed(b);
}

Point::Point(const Point &obj)
{
	*this = obj;
}

Point&	Point::operator=(const Point &obj)
{
	this->_x = obj.getX();
	this->_y = obj.getY();
	return (*this);
}

float	Point::getX(void) const
{
	return (this->_x.toFloat());
}

float	Point::getY(void) const
{
	return (this->_y.toFloat());
}

std::ostream&	operator<<(std::ostream& out, const Point& obj)
{
	out << "(" << obj.getX() << "," << obj.getY() << ")";
	return (out);
}

