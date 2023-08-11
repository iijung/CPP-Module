/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:48:12 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/11 16:15:57 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __A_FORM_H__
# define __A_FORM_H__
# include <cstdlib>
# include <iostream>
# include <exception>
# include <iomanip>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const int			_sign_grade;
		const int			_execute_grade;
	public:
		AForm(void);
		AForm(std::string name, std::string target, int sign_grade, int execute_grade);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm(void);

		const std::string	getName(void) const;
		const std::string	getTarget(void) const;
		bool				getSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecuteGrade(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);
		virtual int			execute(Bureaucrat const & executor) const = 0;
		virtual AForm*		clone(void) const = 0;

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

std::ostream&	operator<<(std::ostream& out, const AForm& obj);

#endif /* __A_FORM_H__ */
