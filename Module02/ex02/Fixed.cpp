/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:21:25 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/14 17:10:39 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = raw << this->_bits;
}

Fixed::Fixed(float const raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(raw * float(1 << this->_bits));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(obj.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_bits);
}

float	Fixed::toFloat(void) const
{
	return (this->getRawBits() / float(1 << this->_bits));
}

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

bool	Fixed::operator>(const Fixed &obj) const
{
	return (this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator<(const Fixed &obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed &obj) const
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed &obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool	Fixed::operator==(const Fixed &obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed &obj) const
{
	return (this->getRawBits() != obj.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &obj) const
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	this->_raw++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->_raw--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	rtn(this->toFloat());

	this->_raw++;
	return (rtn);
}

Fixed	Fixed::operator--(int)
{
	Fixed	rtn(this->toFloat());

	this->_raw--;
	return (rtn);
}

Fixed&	Fixed::max(Fixed &obj1, Fixed &obj2)
{
	return (obj1 >= obj2? obj1: obj2);
}

Fixed&	Fixed::min(Fixed &obj1, Fixed &obj2)
{
	return (obj1 <= obj2? obj1: obj2);
}

const Fixed&	Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 >= obj2? obj1: obj2);
}

const Fixed&	Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	return (obj1 <= obj2? obj1: obj2);
}
