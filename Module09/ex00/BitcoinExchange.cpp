/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:47:11 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/27 15:53:55 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	(void)obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
	if (this == &obj)
		return (*this);
	new (this) BitcoinExchange(obj);
	return (*this);
}

/* ************************************************************************** */
// Utility
/* ************************************************************************** */

static std::string	trim(const std::string& s)
{
	std::string::const_iterator ltrim = s.begin();
	while (ltrim != s.end() && std::isspace(*ltrim))
		ltrim++;
	std::string::const_reverse_iterator	rtrim = s.rbegin();
	while (rtrim != s.rend() && std::isspace(*rtrim))
		rtrim++;
	return (std::string(ltrim, rtrim.base()));
}

static std::string	strtime(const std::tm &t)
{
	std::ostringstream	rtn;

	rtn << std::setfill('0');
	rtn << std::setw(4) << t.tm_year + 1900;
	rtn << "-";
	rtn << std::setw(2) << t.tm_mon + 1;
	rtn << "-";
	rtn << std::setw(2) << t.tm_mday;
	return (rtn.str());
}

static std::time_t	make_time(int year, int month, int day)
{
	std::tm	tm = {};

	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	return (std::mktime(&tm));
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

void	BitcoinExchange::run(const char *file)
{
	// 1. open file
	std::ifstream	in(file, std::ios_base::in);
	if (in.is_open() == false)
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	// 2. read file header
	std::string	line;
	if (std::getline(in, line))
	{
		std::istringstream		header(line);
		std::string				col;
		while (std::getline(header, col, '|'))
			;
	}

	// 3. read file body
	while (std::getline(in, line))
	{
		std::tm				date = {};
		char				delimeter;
		double				value;

		// 4. check format
		std::istringstream	row(line);
		if (!(row >> std::get_time(&date, "%Y-%m-%d"))
			|| !(row >> delimeter && delimeter == '|')
			|| !(row >> value))
		{
			std::cout << "Error: bad input => " << trim(line) << std::endl;
			continue ;
		}
		// 5. check value
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}

		// 6. show
		multimap	_db;
		_db.insert(std::make_pair(make_time(2011, 1, 3), 0.3));
		_db.insert(std::make_pair(make_time(2011, 1, 9), 0.32));
		_db.insert(std::make_pair(make_time(2012, 1, 11), 7.1));

		multimap::const_iterator	it = _db.lower_bound(std::mktime(&date));
		double exchange = it->second;
		std::cout << strtime(date) << " => " << value << " = " << value * exchange << std::endl;
	}
}
