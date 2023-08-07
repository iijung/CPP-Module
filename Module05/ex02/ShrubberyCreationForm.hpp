/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:26:02 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/08 04:58:14 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERY_CREATION_FORM_H__
# define __SHRUBBERY_CREATION_FORM_H__
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &obj);
		virtual ~ShrubberyCreationForm(void);

		int	execute(Bureaucrat const & executor) const;
};

#endif /* __SHRUBBERY_CREATION_FORM_H__ */
