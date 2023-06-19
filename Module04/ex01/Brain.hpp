/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 01:57:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/20 03:50:03 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_H__
# define __BRAIN_H__
# include <iostream>
# include <iomanip>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		virtual ~Brain(void);
		Brain(void);
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);

		std::string	getIdea(int idx) const;
		void		setIdea(int idx, const std::string idea);
		void		fill(const std::string idea);
		void		show(void) const;
};

#endif /* __BRAIN_H__ */
