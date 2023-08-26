/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungkminjungk@student.42se    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:50:26 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/26 15:25:19 by minjungk         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
// Orthodox Canonical Form
/* ************************************************************************** */

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void)
	: std::stack<T, Container>()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &obj)
	: std::stack<T, Container>(obj.c)
{
}

template <typename T, typename Container>
MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack &obj)
{
	if (this == &obj)
		return (*this);
	new (this) MutantStack(obj);
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

template <typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::begin(void)
{
	return this->c.begin();
}

template <typename T, typename Container>
typename Container::const_iterator	MutantStack<T, Container>::begin(void) const
{
	return this->c.begin();
}

template <typename T, typename Container>
typename Container::reverse_iterator	MutantStack<T, Container>::rbegin(void)
{
	return this->c.rbegin();
}

template <typename T, typename Container>
typename Container::const_reverse_iterator	MutantStack<T, Container>::rbegin(void) const
{
	return this->c.rbegin();
}

template <typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::end(void)
{
	return this->c.end();
}

template <typename T, typename Container>
typename Container::const_iterator	MutantStack<T, Container>::end(void) const
{
	return this->c.end();
}

template <typename T, typename Container>
typename Container::reverse_iterator	MutantStack<T, Container>::rend(void)
{
	return this->c.rend();
}

template <typename T, typename Container>
typename Container::const_reverse_iterator	MutantStack<T, Container>::rend(void) const
{
	return this->c.rend();
}

/* ************************************************************************** */
// Non Requirement (for test)
/* ************************************************************************** */

template <typename T, typename Container>
void	MutantStack<T, Container>::show(void) const
{
	typename MutantStack<T, Container>::const_iterator it;

	std::cout << "iterator: ";
	for (it = this->begin(); it != this->end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T, typename Container>
void	MutantStack<T, Container>::rshow(void) const
{
	typename MutantStack<T, Container>::const_reverse_iterator it;

	std::cout << "reverse : ";
	for (it = this->rbegin(); it != this->rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T, typename Container>
void	MutantStack<T, Container>::fill(void)
{
	typename MutantStack<T, Container>::iterator	it;

	int	count = 0;
	for (it = this->begin(); it != this->end(); it++)
		*it = count++;
}

template <typename T, typename Container>
void	MutantStack<T, Container>::rfill(void)
{
	typename MutantStack<T, Container>::reverse_iterator	it;

	int	count = 0;
	for (it = this->rbegin(); it != this->rend(); it++)
		*it = count++;
}
