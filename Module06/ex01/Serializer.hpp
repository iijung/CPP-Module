/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:16:27 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/18 01:44:32 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_H__
# define __SERIALIZER_H__
#include <stdint.h>	// uintptr_t
#include <cstring>	// std::memcpy
#include <iostream>	// std::cout

struct	UDPHeader	
{
	uint16_t	src_port;
	uint16_t	dst_port;
	uint16_t	length;		// header + payload => 8 ~ 65507
	uint16_t	checksum;
};

struct	Data
{
	UDPHeader	header;
	uint8_t*	payload;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &obj);
		Serializer& operator=(const Serializer &obj);
		virtual ~Serializer(void);
	public:
		static uintptr_t	serializer(Data* ptr);
		static Data*		deserializer(uintptr_t raw);
};

#endif /* __SERIALIZER_H__ */
