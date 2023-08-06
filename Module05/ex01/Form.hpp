/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:48:12 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/07 01:05:51 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FORM_H__
# define __FORM_H__
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			sign_grade;
		const int			execute_grade;
	public:
		Form(void);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		virtual ~Form(void);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		const int			getSineGrade(void) const;
		const int			getExecuteGrade(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		}
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		}
};

std::ostream&	operator<<(std::ostream& out, const Form& obj);

#endif /* __FORM_H__ */
