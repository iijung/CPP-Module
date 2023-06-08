/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:43:00 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/08 21:29:11 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once
#ifndef	__PHONEBOOK_H__
#define	__PHONEBOOK_H__
#include "Contact.hpp"

// ************************************************************************** //
//                              PhoneBook Class                               //
// ************************************************************************** //

class PhoneBook
{
	private:
		static const int	MAX_CONTACT = 8;
		int					_num;
		int					_idx;
		class Contact		_contact[8];

		void	_Show(void);
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	Add(void);
		void	Search(void);
};

#endif
