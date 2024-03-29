/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:36:50 by minjungk          #+#    #+#             */
/*   Updated: 2023/09/03 03:12:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __RPN_H__
# define __RPN_H__
# include <stack>
# include <iostream>
# include <cstdlib>

class	RPN
{
	private:
		RPN(void);
		RPN(const RPN& obj);
		RPN& operator=(const RPN& obj);
		virtual ~RPN(void);
	public:
		static void	run(std::string notation);
};

#endif /* __RPN_H__ */
