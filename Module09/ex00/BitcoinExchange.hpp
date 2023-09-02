/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:47:06 by minjungk          #+#    #+#             */
/*   Updated: 2023/09/03 03:09:55 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BITCOIN_EXCHANGE_H__
# define __BITCOIN_EXCHANGE_H__
# include <stdexcept>
# include <string>		// getline
# include <ctime>		// tm, time_t, strftime, strptime
# include <map>			// map
# include <fstream>		// ifstream
# include <sstream>		// istringstream
# include <iostream>	// cout

class BitcoinExchange
{
	private:
		typedef std::map<std::time_t, double>	map;
		map										_db;

		void	_init(const char *file);
	public:
		BitcoinExchange(void);
		BitcoinExchange(const char *file);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		virtual ~BitcoinExchange(void);

		void	run(const char *file);
};

#endif /* __BITCOIN_EXCHANGE_H__ */
