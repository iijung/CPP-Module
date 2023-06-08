/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:43:08 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/08 23:37:38 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once
#ifndef	__CONTACT_H__
#define	__CONTACT_H__
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>

// ************************************************************************** //
//                                Contact Class                               //
// ************************************************************************** //

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

		void	_showField(const std::string& str);
		void	_setField(const std::string& hint, std::string& field);
	public:
		Contact(void);
		~Contact(void);

		void	Set(void);
		void	Show(int index);
		void	ShowDetail(void);
};

#endif
