/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:47:11 by minjungk          #+#    #+#             */
/*   Updated: 2023/09/03 03:08:49 by minjungk         ###   ########.fr       */
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
	this->_init("data.csv");
}

BitcoinExchange::BitcoinExchange(const char *file)
{
	this->_init(file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	this->_db = obj._db;
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

static std::string	strtime(const std::tm &tm)
{
	char	buf[20];

	strftime(buf, sizeof(buf), "%Y-%m-%d", &tm);
	return (std::string(buf));
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

void	BitcoinExchange::_init(const char *file)
{
	// 1. open file
	std::ifstream	in(file, std::ios_base::in);
	if (in.is_open() == false)
		throw std::runtime_error("colud not open database file.");

	// 2. read file header
	std::string	line;
	if (std::getline(in, line))
	{
		std::istringstream		header(line);
		std::string				col;
		while (std::getline(header, col, ','))
			;
	}

	// 3. read file body
	while (std::getline(in, line))
	{
		std::string			date;
		double				exchange_rate;

		if (line.empty())
			continue ;

		// 4. check format
		std::tm				tm = {};
		std::istringstream	row(line);
		if (!(std::getline(row, date, ',') && row >> exchange_rate)
			|| strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
			throw std::runtime_error("invalid file.");

		// 5. insert
		_db.insert(std::make_pair(std::mktime(&tm), exchange_rate));
	}
}

void	BitcoinExchange::run(const char *file)
{
	// 1. open file
	std::ifstream	in(file, std::ios_base::in);
	if (in.is_open() == false)
		throw std::runtime_error("colud not open file.");

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
		std::string			date;
		double				value;
		
		if (line.empty())
			continue ;

		// 4. check format
		std::tm				tm = {};
		std::istringstream	row(line);
		if (!(std::getline(row, date, '|') && row >> value)
			|| strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
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
		map::const_iterator	it = _db.upper_bound(std::mktime(&tm));
		if (it == _db.begin())
		{
			std::cout << "Error: no exchange rate in database." << std::endl;
			continue ;
		}
		--it;
		double exchange = it->second;
		std::cout << strtime(tm) << " => " << value << " = " << value * exchange << std::endl;
	}
}
