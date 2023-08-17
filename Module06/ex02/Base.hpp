/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:56:33 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/18 03:30:47 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_H__
# define __BASE_H__
# include <iostream>
# include <cstdlib>	// std::srand, std::rand
# include <ctime>	// std::time

class Base
{
	public:
		virtual ~Base(void);

};

class A: public Base {};
class B: public Base {};
class C: public Base {};

extern Base*	generate(void);
extern void		identify(Base* p);
extern void		identify(Base& p);

#endif /* __BASE_H__ */
