/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:16:41 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/18 02:10:47 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

Serializer::~Serializer(void)
{
}

Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer &obj)
{
	*this = obj;
}

Serializer&	Serializer::operator=(const Serializer &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

uintptr_t	Serializer::serializer(Data* ptr)
{
	uint8_t	*rtn = new uint8_t[ptr->header.length];

	UDPHeader	*header = reinterpret_cast<UDPHeader*>(rtn);
	{
		header->src_port = ptr->header.src_port;
		header->dst_port = ptr->header.dst_port;
		header->length = ptr->header.length;
		header->checksum = ptr->header.checksum;
	}
	uint8_t*	payload = reinterpret_cast<uint8_t*>(rtn + sizeof(UDPHeader));
	{
		std::memcpy(payload, ptr->payload, header->length - sizeof(UDPHeader));
	}
	return (reinterpret_cast<uintptr_t>(rtn));
}

Data*		Serializer::deserializer(uintptr_t raw)
{
	Data*		rtn = new Data;

	UDPHeader	*header = reinterpret_cast<UDPHeader*>(raw);
	{
		rtn->header.src_port = header->src_port;
		rtn->header.dst_port = header->dst_port;
		rtn->header.length = header->length;
		rtn->header.checksum = header->checksum;
	}
	uint8_t*	payload = reinterpret_cast<uint8_t*>(raw + sizeof(UDPHeader));
	{
		rtn->payload = new uint8_t[rtn->header.length - sizeof(UDPHeader)];
		std::memcpy(rtn->payload, payload, header->length - sizeof(UDPHeader));
	}
	return (rtn);
}
