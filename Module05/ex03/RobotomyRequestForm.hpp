/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:26:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/11 15:47:10 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMY_REQUEST_FORM_H__
# define __ROBOTOMY_REQUEST_FORM_H__
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &obj);
		virtual ~RobotomyRequestForm(void);

		int						execute(Bureaucrat const & executor) const;
		RobotomyRequestForm*	clone(void) const;
};

#endif /* __ROBOTOMY_REQUEST_FORM_H__ */
