/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:11:16 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/07 01:06:19 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BUREAUCRAT_H_
# define __BUREAUCRAT_H_
# include <iostream>
# include <exception>
# include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;	/* range: 1 ~ 150 */
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat& operator=(const Bureaucrat& obj);
		virtual ~Bureaucrat(void);
	
		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				increment(void);
		void				decrement(void);

		void				signForm(const Form& form);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj);

#endif /* __BUREAUCRAT_H_ */
