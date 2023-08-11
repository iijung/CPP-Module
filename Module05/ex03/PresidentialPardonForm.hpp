/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:26:26 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/11 15:47:07 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIAL_PARDON_FORM_H__
# define __PRESIDENTIAL_PARDON_FORM_H__
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &obj);
		virtual ~PresidentialPardonForm(void);

		int						execute(Bureaucrat const & executor) const;
		PresidentialPardonForm*	clone(void) const;
};

#endif /* __PRESIDENTIAL_PARDON_FORM_H__ */
