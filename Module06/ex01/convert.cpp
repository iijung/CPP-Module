/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:17:25 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/18 02:54:15 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstdlib>	// EXIT_SUCCESS, EXIT_FAILURE
#include <iomanip>	// std::setfill, std::setw. std::hex, std::dec, ...

static uint16_t	_checksum(std::string text)
{
	uint16_t	rtn = 0;

	for (uint16_t i = 0; i < text.length(); i++)
		rtn += static_cast<uint16_t>(text.at(i));
	return (rtn);
}

static void	_show_raw(uintptr_t raw, uint16_t len)
{
	// dump character 
	for (uint16_t i = 0; i < len; i++)
	{
		uint8_t	val = *reinterpret_cast<uint8_t*>(raw + i);
		if (std::isprint(val) == false)
			val = '.';
		std::cout << std::setfill(' ') << std::setw(2) << val;
		std::cout << " ";
	}
	std::cout << std::endl;
	// dump hex
	for (uint16_t i = 0; i < len; i++)
	{
		int32_t	val = *reinterpret_cast<uint8_t*>(raw + i);
		std::cout << std::setfill('0') << std::setw(2) << std::hex << val;
		std::cout << " ";
	}
	std::cout << std::endl;
}

static void	_show(Data *data)
{
	std::cout << std::dec;
	std::cout << "# HEADER" << std::endl;
	std::cout << "src_port: " << data->header.src_port << std::endl;
	std::cout << "dst_port: " << data->header.dst_port << std::endl;
	std::cout << "length: " << data->header.length << std::endl;
	std::cout << "checksum: " << data->header.checksum << std::endl;
	std::cout << "# PAYLOAD" << std::endl;
	uintptr_t	payload = reinterpret_cast<uintptr_t>(data->payload);
	_show_raw(payload, data->header.length - sizeof(UDPHeader));
}

static Data*	_init(uint16_t src_port, uint16_t dst_port, std::string text)
{
	Data	*rtn = new Data;

	UDPHeader*	header = reinterpret_cast<UDPHeader*>(rtn);
	{
		header->src_port = src_port;
		header->dst_port = dst_port;
		header->length = sizeof(UDPHeader) + text.length();
		header->checksum = _checksum(text.c_str());
	}
	{
		rtn->payload = new uint8_t[text.length()];
		std::memcpy(rtn->payload, text.c_str(), text.length());
	}
	return (rtn);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <text>" << std::endl;
		return (EXIT_FAILURE);
	}
	Data*		udp;
	uintptr_t	serial;
	Data*		deserial;

	std::cout << std::setfill('=') << std::setw(80) << "INIT" << std::endl;
	{
		udp = _init(443, 60628, argv[1]);
		_show(udp);
	}
	std::cout << std::setfill('=') << std::setw(80) << "SERIAL" << std::endl;
	{
		serial = Serializer::serializer(udp);
		_show_raw(serial, udp->header.length);
	}
	std::cout << std::setfill('=') << std::setw(80) << "DESERIAL" << std::endl;
	{
		deserial = Serializer::deserializer(serial);
		_show(deserial);
	}
	std::cout << std::setfill('=') << std::setw(80) << "END" << std::endl;
	{
		delete[] deserial->payload;
		delete deserial;
		delete[] reinterpret_cast<uint8_t *>(serial);
		delete[] udp->payload;
		delete udp;
	}
	return (EXIT_SUCCESS);
}
