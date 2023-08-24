/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:50:21 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/24 02:05:41 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

Span::~Span(void)
{
}

Span::Span(void)
	: _size(0)
{
	_numbers.reserve(_size);
	std::srand(std::time(NULL));
}

Span::Span(unsigned int n)
	: _size(n)
{
	_numbers.reserve(_size);
	std::srand(std::time(NULL));
}

Span::Span(const Span &obj)
	: _size(obj._size)
{
	std::copy(obj._numbers.begin(), obj._numbers.end(), std::back_inserter(_numbers));
	std::srand(std::time(NULL));
}

Span&	Span::operator=(const Span &obj)
{
	if (this == &obj)
		return (*this);
	new (this) Span(obj);
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

void Span::addNumber(int num)
{
	if (_numbers.size() >= _size)
		throw std::runtime_error("span is full");
	_numbers.push_back(num);
}

void Span::addManyNumber(void)
{
	std::generate_n(std::back_inserter(_numbers), _size, std::rand);
}

static int	_abs(int value)
{
	return value < 0? -value: value;
}

int	Span::shortestSpan(void) const
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("no span can be found");
	std::vector<int>	spans;
	std::adjacent_difference(_numbers.begin(), _numbers.end(), std::back_inserter(spans));
	std::transform(spans.begin(), spans.end(), spans.begin(), _abs);
	return (*std::min_element(spans.begin() + 1, spans.end()));
}

int	Span::longestSpan(void) const
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("no span can be found");
	std::vector<int>	spans;
	std::adjacent_difference(_numbers.begin(), _numbers.end(), std::back_inserter(spans));
	std::transform(spans.begin(), spans.end(), spans.begin(), _abs);
	return (*std::max_element(spans.begin() + 1, spans.end()));
}
