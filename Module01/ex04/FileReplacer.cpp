/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:34:04 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/11 04:52:37 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const char *filename)
{
	std::string	outfile = std::string(filename).append(".replace");

	this->_in.open(filename, std::ios_base::in);
	this->_out.open(outfile.c_str(), std::ios_base::out);
}

FileReplacer::~FileReplacer(void)
{
	this->_in.close();
	this->_out.close();
}

int	FileReplacer::run(const std::string &before, const std::string &after)
{
	std::string				line;
	std::string::size_type	start_pos;
	std::string::size_type	pos;

	if (!(this->_in.is_open() && this->_out.is_open()))
		return (EXIT_FAILURE);
	while (std::getline(this->_in, line))
	{
		if (this->_in.eof())
			break ;
		start_pos = 0;
		while ((pos = line.find(before, start_pos)) != std::string::npos)
		{
			this->_out << line.substr(start_pos, pos - start_pos);
			this->_out << after;
			start_pos = pos + before.length();
		}
		this->_out << line.substr(start_pos) << std::endl;
	}
	return (EXIT_SUCCESS);
}
