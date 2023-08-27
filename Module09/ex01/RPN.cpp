/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:36:55 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/27 17:15:59 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

RPN::~RPN(void)
{
}

RPN::RPN(void)
{
}

RPN::RPN(const RPN& obj)
{
	(void)obj;
}

RPN& RPN::operator=(const RPN& obj)
{
	if (this == &obj)
		return (*this);
	new (this) RPN(obj);
	return (*this);
}

/* ************************************************************************** */
// Utility
/* ************************************************************************** */

static int	_operator(std::stack<int>& calculator, char op)
{
	if (calculator.size() < 2)
		return (EXIT_FAILURE);
	int	num2 = calculator.top(); calculator.pop();
	int	num1 = calculator.top(); calculator.pop();
	switch (op)
	{
		case '+': calculator.push(num1 + num2); break;
		case '-': calculator.push(num1 - num2); break;
		case '*': calculator.push(num1 * num2); break;
		case '/':
		{
			if (num2 == 0)
				return (EXIT_FAILURE);
			calculator.push(num1 / num2);
			break;
		}
		default:
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

void	RPN::run(std::string notation)
{
	std::stack<int>		calculator;

	for (std::string::const_iterator it = notation.begin(); it != notation.end(); it++)
	{
		if (std::isspace(*it))
			continue ;
		if (std::isdigit(*it))
		{
			calculator.push(static_cast<int>(*it - '0'));
			continue ;
		}
		if (_operator(calculator, *it) == EXIT_FAILURE)
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	if (calculator.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	std::cout << calculator.top() << std::endl;
}
