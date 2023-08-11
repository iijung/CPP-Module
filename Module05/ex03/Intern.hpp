/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:15:46 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/11 14:52:04 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __INTERN_H__
# define __INTERN_H__
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &obj);
		Intern& operator=(const Intern &obj);
		virtual	~Intern(void);

		AForm	*makeForm(std::string name, std::string target);

		enum e_form_type
		{
			FORM_NOT_FOUND = 0,
			SHRUBBERY_CREATION,
			ROBOTOMY_REQUEST,
			PRESIDENTIAL_PARDON,
			MAX_FORM_TYPE
		};
		Intern::e_form_type	getFormType(std::string name);
		std::string			getFormName(Intern::e_form_type type);

	private:
		static const std::string	_form_names[MAX_FORM_TYPE];
};

#endif /* __INTERN_H__ */
