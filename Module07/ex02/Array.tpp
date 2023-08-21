/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:59:27 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/20 02:12:44 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

template <typename T>
Array<T>::~Array(void)
{
	delete[] _arr;
}

template <typename T>
Array<T>::Array(void)
	: _size(0)
{
	_arr = new T[_size];
}

template <typename T>
Array<T>::Array(unsigned int n)
	: _size(n)
{
	_arr = new T[_size];
}

template <typename T>
Array<T>::Array(Array const &obj)
	: _size(obj._size)
{
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = obj[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array const &obj)
{
	if (this == &obj)
		return (*this);
	new (this) Array(obj);
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= _size)
		throw std::out_of_range("out of range");
	return _arr[n];
}

template <typename T>
const T&	Array<T>::operator[](unsigned int n) const
{
	if (n >= _size)
		throw std::out_of_range("out of range const");
	return _arr[n];
}

/* ************************************************************************** */
// Etc
/* ************************************************************************** */

template <typename T>
std::ostream&	operator<<(std::ostream &out, const Array<T> &obj)
{
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		if (i == 0)
			out << obj[i];
		else
			out << " " << obj[i];
	}
	return (out);
}
