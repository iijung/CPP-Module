/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:19:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/11 04:52:24 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FILE_REPLACE_H__
# define __FILE_REPLACE_H__
# include <fstream>
# include <cstdlib>

class	FileReplacer
{
	private:
		std::ifstream	_in;
		std::ofstream	_out;
	public:
		FileReplacer(const char *filename);
		~FileReplacer(void);

		int	run(const std::string &before, const std::string &after);
};

#endif /* __FILE_REPLACE_H__ */

