/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:05:57 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/07 01:13:14 by minjungk         ###   ########.fr       */
	std::cout << "Form " << _name << "copy constructor called" << std::endl;
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

Form::~Form(void)
{
	std::cout << "Form " << _name << " destructor called" << std::endl;
}

Form::Form(std::string name)
	_name(name), _signed(false)
{
	std::cout << "Form " << _name << "constructor called" << std::endl;
}


Form::Form(const Form& obj)
	_
{
	std::cout << "Form " << _name << "copy constructor called" << std::endl;
	*this = obj;
}

Form& Form::operator=(const Form& obj)
{

}


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
