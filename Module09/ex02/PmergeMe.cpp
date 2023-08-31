/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:38:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/09/01 00:25:53 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>		// errno
#include <cstdlib>		// strtol

/* ************************************************************************** */
// Utility
/* ************************************************************************** */

static uint32_t	_str2ul(const char *str)
{
	int64_t	num;
	char	*endptr;

	errno = 0;
	num = std::strtol(str, &endptr, 10);
	if (endptr != NULL && *endptr != '\0')
		throw std::invalid_argument("");
	if (errno == ERANGE || num < 0 || num > UINT32_MAX)
		throw std::overflow_error("");
	return (static_cast<uint32_t>(num));
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

std::vector<uint32_t>	make(int argc, char **argv)
{
	std::vector<uint32_t>	rtn;

	rtn.reserve(argc);
	for (int i = 0; i < argc; i++)
		rtn.push_back(_str2ul(argv[i]));
	return (rtn);
}

/* ************************************************************************** */
// Ford Johnson Algorithm (Merge Insertion Sort)
/* ************************************************************************** */

void	ford_johnson(std::vector<uint32_t>& arr)
{
	// 1. if odd, detach last value
	std::vector<uint32_t>	straggler;
	if (arr.size() % 2)
	{
		straggler.push_back(arr.back());
		arr.pop_back();
	}
	// 2. make pair
	std::vector<std::pair<uint32_t, uint32_t> >	pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
		pairs.push_back(std::make_pair(arr[i], arr[i + 1]));

	// 3. sort each pair
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}

	// 4. insertion sort by first
	for (size_t i = 1; i < pairs.size(); i++)
	{
		std::pair<uint32_t, uint32_t>	key = pairs[i];
		size_t j = i;
		while (j > 0 && pairs[j - 1] > key)
		{
			pairs[j] = pairs[j - 1];
			--j;
		}
		pairs[j] = key;
	}

	// 5. create sorted 'S' sequence
	std::vector<uint32_t>	S;
	std::vector<uint32_t>	pend;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		S.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	// 6. sort by jacobstal number
	S.insert(S.begin(), pend[0]);

    std::vector<size_t> jacobSeq;
	jacobSeq.push_back(1);
	jacobSeq.push_back(3);
	for (size_t i = 2; ; i++)
	{
		size_t	next = jacobSeq[i - 1] + 2 * jacobSeq[i - 2];
		jacobSeq.push_back(next);
		if (next >= pend.size())
			break ;
	}

	for (size_t i = 1; i < jacobSeq.size(); i++)
	{
		size_t	range_max = std::min(jacobSeq[i], pend.size());
		size_t	range_min = jacobSeq[i - 1];
		
		for (size_t j = range_max - 1; j >= range_min; j--)
		{
			uint32_t	value = pend[j];
			S.insert(std::lower_bound(S.begin(), S.end(), value), value);
		}
	}

	if (straggler.size())
	{
		uint32_t	value = straggler.front();
		S.insert(std::lower_bound(S.begin(), S.end(), value), value); 
	}
	arr = S;
}

void	ford_johnson(std::deque<uint32_t>& arr)
{
	// 1. if odd, detach last value
	std::deque<uint32_t>	straggler;
	if (arr.size() % 2)
	{
		straggler.push_back(arr.back());
		arr.pop_back();
	}
	// 2. make pair
	std::deque<std::pair<uint32_t, uint32_t> >	pairs;
	for (size_t i = 0; i < arr.size(); i += 2)
		pairs.push_back(std::make_pair(arr[i], arr[i + 1]));

	// 3. sort each pair
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}

	// 4. insertion sort by first
	for (size_t i = 1; i < pairs.size(); i++)
	{
		std::pair<uint32_t, uint32_t>	key = pairs[i];
		size_t j = i;
		while (j > 0 && pairs[j - 1] > key)
		{
			pairs[j] = pairs[j - 1];
			--j;
		}
		pairs[j] = key;
	}

	// 5. create sorted 'S' sequence
	std::deque<uint32_t>	S;
	std::deque<uint32_t>	pend;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		S.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}

	// 6. sort by jacobstal number
	S.insert(S.begin(), pend[0]);

    std::deque<size_t> jacobSeq;
	jacobSeq.push_back(1);
	jacobSeq.push_back(3);
	for (size_t i = 2; ; i++)
	{
		size_t	next = jacobSeq[i - 1] + 2 * jacobSeq[i - 2];
		jacobSeq.push_back(next);
		if (next >= pend.size())
			break ;
	}

	for (size_t i = 1; i < jacobSeq.size(); i++)
	{
		size_t	range_max = std::min(jacobSeq[i], pend.size());
		size_t	range_min = jacobSeq[i - 1];
		
		for (size_t j = range_max - 1; j >= range_min; j--)
		{
			uint32_t	value = pend[j];
			S.insert(std::lower_bound(S.begin(), S.end(), value), value);
		}
	}

	if (straggler.size())
	{
		uint32_t	value = straggler.front();
		S.insert(std::lower_bound(S.begin(), S.end(), value), value); 
	}
	arr = S;
}
