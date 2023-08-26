/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:50:26 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/26 17:22:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MUTANT_STACK_H__
# define __MUTANT_STACK_H__
# include <stack>
# include <iostream>

template <typename T, typename Container = std::deque<T> >
class	MutantStack: public std::stack<T, Container>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &obj);
		MutantStack& operator=(const MutantStack &obj);
		virtual ~MutantStack(void);

		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		iterator				begin(void);
		const_iterator			begin(void) const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void) const;

		iterator				end(void);
		const_iterator			end(void) const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void) const;

		// for test
		void	show(void) const;
		void	rshow(void) const;
		void	fill(void);
		void	rfill(void);
};

# include "MutantStack.tpp"

#endif /* __MUTANT_STACK_H__ */
