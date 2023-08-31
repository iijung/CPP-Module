/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:47:06 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/27 15:54:28 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BITCOIN_EXCHANGE_H__
# define __BITCOIN_EXCHANGE_H__
# include <stdexcept>
# include <string>		// getline
# include <ctime>		// tm, time_t, get_time
# include <map>			// multimap
# include <fstream>		// ifstream
# include <sstream>		// istringstream, ostringstream
# include <iostream>	// cout

class BitcoinExchange
{
	private:
		typedef std::multimap<std::time_t, double>	multimap;

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		virtual ~BitcoinExchange(void);
	public:
		static void	run(const char *file);
};

#endif /* __BITCOIN_EXCHANGE_H__ */