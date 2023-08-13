/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 03:03:05 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/13 15:29:06 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

/* ************************************************************************** */
// Orthodox Canonical Class Form
/* ************************************************************************** */

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", "default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj)
	: AForm(obj)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this == &obj)
		return (*this);
	new (this) ShrubberyCreationForm(obj);
	return (*this);
}

/* ************************************************************************** */
// Requirement
/* ************************************************************************** */

int	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	if (this->getExecuteGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::string		name = this->getTarget() + "_shrubbery";
	std::ofstream	out(name.c_str(), std::ios_base::out);
	
	if (!out.is_open())
		throw std::ios_base::failure("Field to open file");
	for (std::string::size_type i = 0; i < 30; i++)
		out << this->_white_pink_salix[i] << std::endl;
	out.close();
	return (EXIT_SUCCESS);
}

ShrubberyCreationForm*	ShrubberyCreationForm::clone(void) const
{
	return (new ShrubberyCreationForm(*this));
}

/* ************************************************************************** */
// 삼색버드나무	(Salix integra Hakuro - nishiki)
// - image : https://gogirifarm.org/106/?idx=118
// - converter : https://dom111.github.io/image-to-ansi/
/* ************************************************************************** */

const char	*ShrubberyCreationForm::_white_pink_salix[] = {
	"[48;5;0m                    [38;5;;48;5;233m▄[38;5;181;48;5;181m▄[38;5;237;48;5;248m▄[38;5;175;48;5;181m▄[38;5;250;48;5;236m▄[38;5;233;48;5;234m▄[48;5;0m   [38;5;235;48;5;0m▄[38;5;233;48;5;0m▄[38;5;174;48;5;138m▄[38;5;95;48;5;235m▄[48;5;0m  [38;5;233;48;5;0m▄[38;5;251;48;5;242m▄[38;5;181;48;5;237m▄[38;5;138;48;5;237m▄[38;5;235;48;5;95m▄[38;5;232;48;5;59m▄[38;5;232;48;5;0m▄[48;5;0m                  [m",
	"[48;5;0m                  [38;5;95;48;5;234m▄[38;5;238;48;5;0m▄[38;5;233;48;5;95m▄[38;5;180;48;5;175m▄[38;5;246;48;5;m▄[38;5;240;48;5;247m▄[38;5;180;48;5;251m▄[38;5;239;48;5;235m▄[38;5;232;48;5;0m▄[38;5;8;48;5;234m▄[38;5;174;48;5;233m▄▄[38;5;174;48;5;235m▄[38;5;217;48;5;174m▄[38;5;8;48;5;95m▄[38;5;232;48;5;0m▄[38;5;233;48;5;0m▄[38;5;251;48;5;95m▄[38;5;59;48;5;181m▄[38;5;232;48;5;237m▄[38;5;232;48;5;0m▄[48;5;0m                     [m",
	"[48;5;0m     [38;5;234;48;5;233m▄[38;5;95;48;5;234m▄[38;5;235;48;5;0m▄[38;5;235;48;5;233m▄[48;5;0m       [38;5;234;48;5;0m▄[38;5;250;48;5;0m▄[38;5;247;48;5;239m▄[38;5;224;48;5;247m▄[38;5;235;48;5;0m▄[38;5;237;48;5;240m▄[38;5;187;48;5;187m▄[38;5;;48;5;233m▄[38;5;233;48;5;239m▄[38;5;95;48;5;144m▄[38;5;181;48;5;234m▄[38;5;239;48;5;95m▄[38;5;232;48;5;234m▄[38;5;234;48;5;234m▄[38;5;237;48;5;131m▄[38;5;174;48;5;174m▄▄[38;5;236;48;5;233m▄[38;5;181;48;5;237m▄[38;5;7;48;5;246m▄[38;5;238;48;5;0m▄[38;5;232;48;5;0m▄[48;5;0m [38;5;236;48;5;0m▄[38;5;95;48;5;233m▄[38;5;235;48;5;234m▄[48;5;0m         [38;5;232;48;5;0m▄[38;5;233;48;5;0m▄[38;5;232;48;5;0m▄[48;5;0m      [m",
	"[48;5;0m     [38;5;232;48;5;233m▄[38;5;233;48;5;238m▄[38;5;238;48;5;95m▄[38;5;138;48;5;243m▄[38;5;95;48;5;233m▄[38;5;233;48;5;0m▄[38;5;237;48;5;233m▄[48;5;0m    [38;5;232;48;5;234m▄[38;5;238;48;5;174m▄[38;5;174;48;5;224m▄[38;5;181;48;5;251m▄[38;5;187;48;5;137m▄[38;5;138;48;5;m▄[38;5;144;48;5;181m▄[38;5;138;48;5;138m▄[38;5;173;48;5;137m▄[38;5;131;48;5;236m▄[38;5;95;48;5;137m▄[38;5;102;48;5;239m▄[38;5;95;48;5;0m▄[38;5;95;48;5;233m▄[38;5;167;48;5;181m▄[38;5;174;48;5;175m▄[38;5;180;48;5;180m▄[38;5;180;48;5;167m▄[38;5;180;48;5;180m▄[38;5;252;48;5;150m▄[38;5;181;48;5;175m▄[38;5;138;48;5;239m▄[38;5;238;48;5;238m▄[38;5;174;48;5;238m▄[38;5;138;48;5;173m▄[38;5;235;48;5;234m▄[48;5;0m     [38;5;234;48;5;0m▄▄[38;5;232;48;5;0m▄[38;5;102;48;5;237m▄[38;5;248;48;5;95m▄[38;5;238;48;5;59m▄[38;5;232;48;5;233m▄[48;5;0m      [m",
	"[48;5;0m       [38;5;232;48;5;233m▄[38;5;234;48;5;138m▄[38;5;101;48;5;181m▄[38;5;137;48;5;235m▄[38;5;101;48;5;240m▄[38;5;243;48;5;233m▄[38;5;233;48;5;0m▄[48;5;0m [38;5;235;48;5;0m▄[38;5;131;48;5;238m▄[38;5;95;48;5;0m▄[38;5;233;48;5;238m▄[38;5;173;48;5;181m▄[38;5;240;48;5;8m▄[38;5;95;48;5;181m▄[38;5;144;48;5;240m▄[38;5;137;48;5;137m▄[38;5;;48;5;173m▄[38;5;137;48;5;174m▄[38;5;174;48;5;168m▄[38;5;174;48;5;181m▄[38;5;95;48;5;181m▄[38;5;242;48;5;101m▄[38;5;233;48;5;95m▄[38;5;131;48;5;174m▄[38;5;174;48;5;174m▄[38;5;174;48;5;180m▄▄[38;5;239;48;5;240m▄[38;5;131;48;5;174m▄[38;5;180;48;5;131m▄[38;5;137;48;5;95m▄[38;5;236;48;5;131m▄[38;5;245;48;5;234m▄[38;5;240;48;5;0m▄[38;5;102;48;5;0m▄[38;5;237;48;5;0m▄[48;5;0m  [38;5;232;48;5;0m▄[38;5;239;48;5;236m▄[38;5;251;48;5;240m▄[38;5;144;48;5;246m▄[38;5;240;48;5;245m▄[38;5;235;48;5;237m▄[38;5;232;48;5;234m▄[48;5;0m       [m",
	"[48;5;0m       [38;5;232;48;5;0m▄[38;5;95;48;5;0m▄[38;5;239;48;5;234m▄[38;5;232;48;5;102m▄[38;5;;48;5;173m▄[38;5;174;48;5;248m▄[38;5;181;48;5;242m▄[38;5;101;48;5;233m▄[38;5;232;48;5;235m▄[38;5;235;48;5;174m▄[38;5;174;48;5;181m▄[38;5;238;48;5;233m▄[38;5;234;48;5;239m▄[38;5;101;48;5;144m▄[38;5;137;48;5;180m▄[38;5;174;48;5;180m▄[38;5;144;48;5;107m▄[38;5;107;48;5;235m▄[38;5;237;48;5;239m▄[38;5;107;48;5;144m▄[38;5;144;48;5;173m▄[38;5;107;48;5;241m▄[38;5;101;48;5;107m▄[38;5;107;48;5;237m▄[38;5;58;48;5;95m▄[38;5;167;48;5;174m▄[38;5;137;48;5;174m▄[38;5;137;48;5;173m▄[38;5;236;48;5;101m▄[38;5;101;48;5;131m▄[38;5;239;48;5;101m▄[38;5;233;48;5;235m▄[38;5;232;48;5;0m▄[38;5;237;48;5;233m▄[38;5;253;48;5;188m▄[38;5;253;48;5;181m▄[38;5;137;48;5;234m▄[38;5;233;48;5;0m▄[38;5;241;48;5;233m▄[38;5;144;48;5;237m▄[38;5;144;48;5;187m▄[38;5;236;48;5;250m▄[38;5;240;48;5;247m▄[38;5;237;48;5;233m▄[38;5;232;48;5;237m▄[48;5;0m        [m",
	"[48;5;0m    [38;5;233;48;5;233m▄[38;5;237;48;5;233m▄[38;5;;48;5;234m▄[38;5;232;48;5;0m▄[38;5;234;48;5;239m▄[38;5;131;48;5;175m▄[38;5;131;48;5;237m▄[38;5;181;48;5;236m▄[38;5;138;48;5;131m▄[38;5;181;48;5;181m▄[38;5;250;48;5;144m▄[38;5;143;48;5;240m▄[38;5;101;48;5;237m▄[38;5;239;48;5;237m▄[38;5;242;48;5;138m▄[38;5;235;48;5;0m▄[38;5;238;48;5;237m▄[38;5;131;48;5;137m▄[38;5;101;48;5;131m▄[38;5;243;48;5;180m▄[38;5;144;48;5;187m▄[38;5;143;48;5;242m▄[38;5;144;48;5;144m▄[38;5;65;48;5;107m▄[38;5;106;48;5;107m▄[38;5;71;48;5;65m▄[38;5;107;48;5;107m▄[38;5;101;48;5;107m▄[38;5;95;48;5;3m▄[38;5;58;48;5;58m▄[38;5;137;48;5;101m▄[38;5;137;48;5;65m▄[38;5;64;48;5;64m▄[38;5;101;48;5;58m▄[38;5;237;48;5;0m▄[38;5;181;48;5;101m▄[38;5;251;48;5;144m▄[38;5;251;48;5;250m▄[38;5;238;48;5;65m▄[38;5;248;48;5;243m▄[38;5;249;48;5;246m▄[38;5;65;48;5;145m▄[38;5;240;48;5;65m▄[38;5;234;48;5;239m▄[38;5;232;48;5;235m▄[38;5;232;48;5;0m▄[38;5;232;48;5;234m▄[48;5;0m         [m",
	"[48;5;0m    [38;5;232;48;5;233m▄[38;5;233;48;5;m▄[38;5;138;48;5;131m▄[38;5;137;48;5;233m▄[38;5;181;48;5;239m▄[38;5;238;48;5;235m▄[38;5;232;48;5;95m▄[38;5;95;48;5;174m▄[38;5;181;48;5;224m▄[38;5;180;48;5;174m▄[38;5;174;48;5;138m▄[38;5;95;48;5;58m▄[38;5;234;48;5;101m▄[38;5;235;48;5;101m▄[38;5;238;48;5;240m▄[38;5;239;48;5;101m▄[38;5;180;48;5;174m▄▄[38;5;101;48;5;243m▄[38;5;237;48;5;237m▄[38;5;239;48;5;65m▄[38;5;65;48;5;107m▄[38;5;101;48;5;144m▄[38;5;65;48;5;65m▄[38;5;65;48;5;58m▄[38;5;64;48;5;65m▄[38;5;64;48;5;64m▄[38;5;243;48;5;131m▄[38;5;238;48;5;95m▄[38;5;107;48;5;65m▄[38;5;242;48;5;137m▄[38;5;65;48;5;65m▄[38;5;64;48;5;65m▄[38;5;65;48;5;65m▄[38;5;137;48;5;180m▄[38;5;65;48;5;180m▄[38;5;65;48;5;250m▄[38;5;247;48;5;107m▄[38;5;107;48;5;144m▄[38;5;65;48;5;107m▄▄[38;5;238;48;5;8m▄[38;5;234;48;5;240m▄[38;5;232;48;5;0m▄[38;5;233;48;5;0m▄[38;5;8;48;5;233m▄[38;5;239;48;5;0m▄[38;5;233;48;5;0m▄[48;5;0m [38;5;234;48;5;0m▄[38;5;242;48;5;0m▄[38;5;181;48;5;235m▄[38;5;59;48;5;235m▄[38;5;234;48;5;0m▄[38;5;232;48;5;0m▄[48;5;0m [m",
	"[48;5;0m      [38;5;234;48;5;0m▄[38;5;95;48;5;238m▄[38;5;138;48;5;173m▄[38;5;174;48;5;138m▄[38;5;95;48;5;234m▄[48;5;0m [38;5;234;48;5;237m▄[38;5;137;48;5;137m▄[38;5;137;48;5;101m▄[38;5;107;48;5;180m▄[38;5;101;48;5;137m▄[38;5;64;48;5;234m▄[38;5;64;48;5;235m▄[38;5;233;48;5;238m▄[38;5;95;48;5;180m▄[38;5;174;48;5;180m▄[38;5;144;48;5;143m▄[38;5;144;48;5;65m▄[38;5;242;48;5;239m▄[38;5;64;48;5;65m▄[38;5;138;48;5;174m▄[38;5;95;48;5;101m▄[38;5;249;48;5;64m▄[38;5;101;48;5;65m▄[38;5;240;48;5;242m▄[38;5;94;48;5;131m▄[38;5;238;48;5;58m▄[38;5;95;48;5;238m▄[38;5;242;48;5;59m▄[38;5;58;48;5;65m▄[38;5;65;48;5;65m▄[38;5;101;48;5;137m▄[38;5;137;48;5;101m▄[38;5;107;48;5;65m▄[38;5;65;48;5;107m▄[38;5;101;48;5;180m▄[38;5;241;48;5;181m▄[38;5;239;48;5;137m▄[38;5;65;48;5;238m▄[38;5;144;48;5;237m▄[38;5;239;48;5;233m▄[38;5;138;48;5;233m▄[38;5;180;48;5;138m▄[38;5;173;48;5;181m▄[38;5;174;48;5;174m▄[38;5;253;48;5;243m▄[38;5;181;48;5;239m▄[38;5;217;48;5;181m▄[38;5;174;48;5;224m▄[38;5;174;48;5;251m▄[38;5;131;48;5;7m▄[38;5;235;48;5;181m▄[38;5;232;48;5;235m▄[48;5;0m [m",
	"[38;5;235;48;5;233m▄[38;5;233;48;5;0m▄[38;5;232;48;5;0m▄[48;5;0m     [38;5;232;48;5;0m▄[38;5;232;48;5;238m▄[38;5;232;48;5;137m▄[38;5;101;48;5;238m▄[38;5;101;48;5;235m▄[38;5;232;48;5;95m▄[38;5;234;48;5;173m▄[38;5;95;48;5;137m▄[38;5;137;48;5;101m▄[38;5;239;48;5;64m▄[38;5;138;48;5;65m▄[38;5;174;48;5;59m▄[38;5;174;48;5;101m▄[38;5;224;48;5;137m▄[38;5;174;48;5;174m▄[38;5;101;48;5;101m▄[38;5;238;48;5;65m▄[38;5;181;48;5;137m▄[38;5;138;48;5;101m▄[38;5;167;48;5;174m▄[38;5;180;48;5;174m▄[38;5;240;48;5;65m▄[38;5;237;48;5;58m▄[38;5;58;48;5;94m▄[38;5;239;48;5;239m▄[38;5;234;48;5;239m▄[38;5;58;48;5;131m▄[38;5;237;48;5;101m▄[38;5;238;48;5;65m▄[38;5;239;48;5;64m▄[38;5;143;48;5;101m▄[38;5;101;48;5;65m▄[38;5;65;48;5;101m▄[38;5;70;48;5;65m▄[38;5;107;48;5;64m▄[38;5;107;48;5;65m▄[38;5;180;48;5;144m▄[38;5;137;48;5;144m▄[38;5;101;48;5;180m▄[38;5;180;48;5;174m▄[38;5;107;48;5;144m▄[38;5;64;48;5;101m▄[38;5;144;48;5;181m▄[38;5;181;48;5;181m▄[38;5;173;48;5;180m▄[38;5;181;48;5;180m▄[38;5;217;48;5;181m▄[38;5;95;48;5;95m▄[38;5;232;48;5;95m▄[38;5;232;48;5;240m▄[38;5;232;48;5;0m▄[48;5;0m [m",
	"[38;5;234;48;5;234m▄[38;5;235;48;5;m▄[38;5;131;48;5;95m▄[38;5;174;48;5;235m▄[38;5;233;48;5;0m▄[38;5;239;48;5;233m▄[38;5;234;48;5;236m▄[48;5;0m  [38;5;232;48;5;233m▄[38;5;232;48;5;239m▄[38;5;233;48;5;101m▄[38;5;239;48;5;143m▄[38;5;242;48;5;101m▄[38;5;101;48;5;238m▄[38;5;65;48;5;235m▄[38;5;236;48;5;242m▄[38;5;238;48;5;65m▄[38;5;241;48;5;174m▄[38;5;131;48;5;167m▄[38;5;174;48;5;173m▄[38;5;137;48;5;138m▄[38;5;173;48;5;181m▄[38;5;173;48;5;174m▄▄▄[38;5;131;48;5;167m▄[38;5;239;48;5;137m▄[38;5;236;48;5;101m▄[38;5;236;48;5;65m▄[38;5;237;48;5;235m▄[38;5;236;48;5;237m▄[38;5;233;48;5;234m▄[38;5;234;48;5;233m▄[38;5;235;48;5;237m▄[38;5;59;48;5;236m▄[38;5;237;48;5;238m▄[38;5;239;48;5;64m▄[38;5;237;48;5;64m▄[38;5;65;48;5;64m▄[38;5;242;48;5;64m▄[38;5;65;48;5;3m▄[38;5;65;48;5;95m▄[38;5;137;48;5;143m▄[38;5;174;48;5;180m▄[38;5;174;48;5;181m▄▄[38;5;137;48;5;187m▄[38;5;65;48;5;180m▄[38;5;144;48;5;144m▄[38;5;107;48;5;7m▄[38;5;252;48;5;250m▄[38;5;251;48;5;181m▄[38;5;251;48;5;217m▄[38;5;181;48;5;174m▄[38;5;137;48;5;138m▄[38;5;233;48;5;236m▄[48;5;0m   [m",
	"[38;5;232;48;5;0m▄[38;5;232;48;5;233m▄[38;5;232;48;5;m▄[38;5;233;48;5;168m▄[38;5;131;48;5;138m▄[38;5;174;48;5;181m▄[38;5;174;48;5;237m▄[38;5;237;48;5;0m▄[38;5;234;48;5;0m▄[38;5;232;48;5;0m▄[48;5;0m  [38;5;232;48;5;233m▄[38;5;95;48;5;95m▄[38;5;138;48;5;240m▄[38;5;137;48;5;65m▄[38;5;65;48;5;65m▄[38;5;65;48;5;238m▄▄[38;5;239;48;5;235m▄[38;5;131;48;5;174m▄[38;5;174;48;5;138m▄[38;5;180;48;5;174m▄[38;5;174;48;5;174m▄▄[38;5;101;48;5;137m▄[38;5;95;48;5;131m▄[38;5;101;48;5;101m▄[38;5;239;48;5;236m▄[38;5;238;48;5;237m▄[38;5;237;48;5;58m▄[38;5;95;48;5;239m▄[38;5;174;48;5;234m▄[38;5;174;48;5;233m▄[38;5;144;48;5;59m▄[38;5;138;48;5;144m▄[38;5;237;48;5;238m▄[38;5;240;48;5;238m▄[38;5;240;48;5;240m▄[38;5;101;48;5;237m▄[38;5;251;48;5;101m▄[38;5;65;48;5;239m▄[38;5;101;48;5;71m▄[38;5;137;48;5;143m▄[38;5;137;48;5;174m▄[38;5;137;48;5;137m▄[38;5;238;48;5;241m▄[38;5;240;48;5;239m▄[38;5;239;48;5;65m▄[38;5;181;48;5;144m▄[38;5;173;48;5;143m▄[38;5;174;48;5;180m▄[38;5;144;48;5;180m▄[38;5;187;48;5;180m▄[38;5;249;48;5;181m▄[38;5;243;48;5;235m▄[38;5;95;48;5;233m▄[38;5;239;48;5;0m▄[38;5;237;48;5;0m▄[38;5;232;48;5;0m▄[m",
	"[48;5;0m  [38;5;232;48;5;239m▄[38;5;232;48;5;138m▄[38;5;232;48;5;237m▄[38;5;237;48;5;131m▄[38;5;137;48;5;173m▄[38;5;131;48;5;173m▄[38;5;173;48;5;181m▄[38;5;174;48;5;138m▄[38;5;180;48;5;242m▄[38;5;138;48;5;234m▄[38;5;95;48;5;0m▄[38;5;240;48;5;0m▄[38;5;64;48;5;234m▄[38;5;238;48;5;234m▄[38;5;239;48;5;239m▄[38;5;239;48;5;65m▄[38;5;237;48;5;65m▄[38;5;95;48;5;174m▄[38;5;95;48;5;167m▄[38;5;167;48;5;174m▄[38;5;174;48;5;217m▄[38;5;173;48;5;167m▄[38;5;173;48;5;174m▄[38;5;167;48;5;181m▄[38;5;131;48;5;3m▄[38;5;137;48;5;101m▄[38;5;180;48;5;137m▄[38;5;174;48;5;95m▄▄[38;5;174;48;5;138m▄[38;5;180;48;5;239m▄[38;5;174;48;5;138m▄[38;5;174;48;5;174m▄[38;5;138;48;5;237m▄[38;5;59;48;5;240m▄[38;5;143;48;5;144m▄[38;5;174;48;5;138m▄[38;5;174;48;5;181m▄[38;5;101;48;5;65m▄[38;5;239;48;5;237m▄[38;5;237;48;5;101m▄[38;5;242;48;5;101m▄[38;5;101;48;5;101m▄[38;5;137;48;5;173m▄[38;5;101;48;5;101m▄[38;5;187;48;5;137m▄[38;5;138;48;5;101m▄[38;5;174;48;5;217m▄[38;5;95;48;5;137m▄[38;5;237;48;5;246m▄[38;5;232;48;5;243m▄[38;5;233;48;5;243m▄[38;5;232;48;5;233m▄[38;5;234;48;5;237m▄[38;5;235;48;5;237m▄[38;5;232;48;5;95m▄[38;5;232;48;5;137m▄[38;5;232;48;5;239m▄[m",
	"[48;5;0m     [38;5;232;48;5;0m▄[38;5;237;48;5;0m▄[38;5;95;48;5;m▄[38;5;131;48;5;101m▄[38;5;238;48;5;3m▄[38;5;238;48;5;101m▄[38;5;101;48;5;101m▄[38;5;101;48;5;233m▄[38;5;3;48;5;238m▄[38;5;65;48;5;65m▄[38;5;239;48;5;239m▄[38;5;240;48;5;236m▄[38;5;239;48;5;242m▄[38;5;237;48;5;237m▄[38;5;240;48;5;243m▄[38;5;101;48;5;238m▄[38;5;95;48;5;238m▄[38;5;137;48;5;173m▄[38;5;167;48;5;174m▄[38;5;180;48;5;137m▄[38;5;101;48;5;131m▄[38;5;239;48;5;137m▄[38;5;95;48;5;131m▄[38;5;58;48;5;101m▄[38;5;174;48;5;174m▄[38;5;101;48;5;101m▄[38;5;59;48;5;137m▄[38;5;59;48;5;168m▄[38;5;59;48;5;173m▄[38;5;236;48;5;181m▄[38;5;235;48;5;240m▄[38;5;238;48;5;65m▄[38;5;59;48;5;101m▄[38;5;240;48;5;137m▄[38;5;59;48;5;131m▄[38;5;235;48;5;138m▄[38;5;235;48;5;247m▄[38;5;237;48;5;237m▄[38;5;237;48;5;101m▄[38;5;239;48;5;64m▄[38;5;58;48;5;64m▄[38;5;101;48;5;137m▄[38;5;101;48;5;181m▄[38;5;101;48;5;180m▄[38;5;65;48;5;131m▄[38;5;65;48;5;144m▄[38;5;101;48;5;174m▄[38;5;131;48;5;8m▄[38;5;95;48;5;238m▄[38;5;131;48;5;0m▄[38;5;59;48;5;0m▄[38;5;237;48;5;0m▄[38;5;234;48;5;0m▄[48;5;0m  [m",
	"[48;5;0m      [38;5;234;48;5;238m▄[38;5;237;48;5;167m▄[38;5;235;48;5;131m▄[38;5;;48;5;174m▄[38;5;95;48;5;137m▄[38;5;95;48;5;95m▄[38;5;241;48;5;64m▄[38;5;65;48;5;71m▄[38;5;238;48;5;107m▄[38;5;237;48;5;65m▄[38;5;239;48;5;65m▄[38;5;242;48;5;101m▄[38;5;58;48;5;238m▄[38;5;64;48;5;239m▄[38;5;58;48;5;239m▄[38;5;238;48;5;58m▄[38;5;237;48;5;58m▄[38;5;58;48;5;95m▄[38;5;240;48;5;173m▄[38;5;137;48;5;180m▄[38;5;138;48;5;58m▄[38;5;240;48;5;65m▄[38;5;236;48;5;236m▄[38;5;59;48;5;137m▄[38;5;58;48;5;3m▄[38;5;235;48;5;235m▄[38;5;235;48;5;237m▄[38;5;238;48;5;237m▄[38;5;234;48;5;236m▄[38;5;233;48;5;235m▄[38;5;235;48;5;235m▄[38;5;235;48;5;236m▄[38;5;241;48;5;236m▄[38;5;131;48;5;238m▄[38;5;131;48;5;240m▄[38;5;239;48;5;238m▄[38;5;236;48;5;236m▄[38;5;235;48;5;235m▄[38;5;233;48;5;235m▄[38;5;236;48;5;236m▄[38;5;59;48;5;242m▄[38;5;65;48;5;101m▄[38;5;242;48;5;144m▄[38;5;242;48;5;137m▄[38;5;101;48;5;137m▄[38;5;95;48;5;241m▄[38;5;235;48;5;137m▄[38;5;236;48;5;138m▄[38;5;234;48;5;174m▄[38;5;95;48;5;181m▄[38;5;181;48;5;8m▄[38;5;138;48;5;234m▄[38;5;137;48;5;0m▄[38;5;95;48;5;0m▄[m",
	"[48;5;0m              [38;5;232;48;5;0m▄[38;5;232;48;5;234m▄[38;5;232;48;5;m▄[38;5;232;48;5;0m▄[38;5;234;48;5;238m▄[38;5;237;48;5;237m▄[38;5;237;48;5;234m▄[38;5;236;48;5;235m▄[38;5;236;48;5;236m▄[38;5;236;48;5;235m▄[38;5;234;48;5;236m▄[38;5;235;48;5;237m▄[38;5;236;48;5;58m▄[38;5;240;48;5;241m▄[38;5;58;48;5;236m▄[38;5;237;48;5;238m▄[38;5;237;48;5;58m▄[38;5;240;48;5;235m▄[38;5;101;48;5;239m▄[38;5;143;48;5;240m▄[38;5;138;48;5;138m▄[38;5;101;48;5;236m▄[38;5;64;48;5;236m▄[38;5;58;48;5;59m▄[38;5;131;48;5;144m▄[38;5;95;48;5;131m▄[38;5;235;48;5;238m▄[38;5;236;48;5;239m▄[38;5;237;48;5;237m▄[38;5;239;48;5;238m▄[38;5;238;48;5;242m▄[38;5;239;48;5;239m▄[38;5;101;48;5;144m▄[38;5;143;48;5;65m▄[38;5;238;48;5;101m▄[38;5;233;48;5;58m▄[38;5;233;48;5;95m▄[38;5;235;48;5;236m▄[38;5;95;48;5;234m▄[38;5;137;48;5;237m▄[38;5;233;48;5;0m▄[38;5;232;48;5;0m▄[38;5;232;48;5;241m▄[38;5;232;48;5;234m▄[38;5;232;48;5;233m▄[38;5;232;48;5;235m▄[m",
	"[48;5;0m                [38;5;235;48;5;0m▄[38;5;;48;5;0m▄[38;5;232;48;5;0m▄[38;5;236;48;5;235m▄[38;5;236;48;5;234m▄[38;5;236;48;5;235m▄[38;5;237;48;5;237m▄[38;5;236;48;5;235m▄[38;5;233;48;5;234m▄▄[38;5;232;48;5;0m▄[38;5;234;48;5;235m▄[38;5;233;48;5;237m▄[38;5;235;48;5;237m▄[38;5;236;48;5;236m▄[38;5;238;48;5;237m▄[38;5;235;48;5;237m▄[38;5;131;48;5;131m▄[38;5;95;48;5;95m▄[38;5;236;48;5;58m▄[38;5;233;48;5;237m▄[38;5;236;48;5;236m▄[38;5;238;48;5;95m▄[38;5;236;48;5;239m▄[38;5;235;48;5;235m▄▄[38;5;233;48;5;235m▄[38;5;236;48;5;235m▄[38;5;237;48;5;0m▄▄[38;5;234;48;5;237m▄[38;5;245;48;5;237m▄[38;5;138;48;5;0m▄[38;5;233;48;5;0m▄[48;5;0m  [38;5;232;48;5;0m▄[38;5;232;48;5;233m▄[48;5;0m      [m",
	"[48;5;0m              [38;5;232;48;5;0m▄[38;5;95;48;5;233m▄[38;5;131;48;5;m▄[38;5;131;48;5;131m▄[38;5;235;48;5;131m▄[38;5;232;48;5;241m▄[38;5;232;48;5;236m▄▄[38;5;236;48;5;95m▄[38;5;173;48;5;95m▄[38;5;235;48;5;58m▄[38;5;232;48;5;238m▄[38;5;234;48;5;235m▄[38;5;234;48;5;234m▄[38;5;233;48;5;234m▄[38;5;234;48;5;234m▄[38;5;235;48;5;235m▄[38;5;237;48;5;238m▄[38;5;234;48;5;235m▄[38;5;235;48;5;95m▄[38;5;239;48;5;95m▄[38;5;233;48;5;234m▄[38;5;235;48;5;234m▄[38;5;239;48;5;236m▄[38;5;101;48;5;238m▄[38;5;59;48;5;239m▄[38;5;95;48;5;236m▄[38;5;137;48;5;236m▄[38;5;95;48;5;236m▄[38;5;237;48;5;237m▄[38;5;239;48;5;236m▄[38;5;237;48;5;235m▄[38;5;236;48;5;235m▄[38;5;239;48;5;59m▄[38;5;239;48;5;131m▄[38;5;137;48;5;137m▄[38;5;8;48;5;0m▄[38;5;235;48;5;0m▄[38;5;238;48;5;0m▄[38;5;137;48;5;233m▄[38;5;95;48;5;235m▄[38;5;235;48;5;0m▄▄[38;5;239;48;5;0m▄[48;5;0m  [m",
	"[48;5;0m              [38;5;232;48;5;233m▄[38;5;232;48;5;m▄[38;5;232;48;5;234m▄[38;5;232;48;5;235m▄[48;5;0m [38;5;232;48;5;0m▄[38;5;236;48;5;0m▄[38;5;234;48;5;0m▄[38;5;233;48;5;0m▄[38;5;95;48;5;137m▄[38;5;131;48;5;167m▄[38;5;137;48;5;131m▄[38;5;131;48;5;95m▄[38;5;242;48;5;101m▄[38;5;238;48;5;238m▄[38;5;236;48;5;237m▄[38;5;235;48;5;236m▄[38;5;237;48;5;237m▄[38;5;234;48;5;237m▄[38;5;235;48;5;236m▄[38;5;234;48;5;235m▄[38;5;235;48;5;235m▄[38;5;235;48;5;236m▄[38;5;235;48;5;238m▄[38;5;235;48;5;241m▄[38;5;239;48;5;240m▄[38;5;137;48;5;131m▄[38;5;174;48;5;173m▄[38;5;95;48;5;137m▄[38;5;101;48;5;239m▄[38;5;65;48;5;59m▄[38;5;65;48;5;65m▄[38;5;65;48;5;238m▄[38;5;64;48;5;234m▄[38;5;235;48;5;233m▄[38;5;233;48;5;238m▄[38;5;131;48;5;95m▄[38;5;237;48;5;95m▄[38;5;232;48;5;137m▄[38;5;232;48;5;167m▄[38;5;239;48;5;181m▄[38;5;167;48;5;181m▄[38;5;168;48;5;175m▄[38;5;175;48;5;95m▄[38;5;237;48;5;233m▄[48;5;0m [m",
	"[48;5;0m                   [38;5;232;48;5;0m▄[38;5;232;48;5;m▄[38;5;236;48;5;95m▄[38;5;235;48;5;95m▄[38;5;232;48;5;239m▄[38;5;232;48;5;234m▄▄[38;5;232;48;5;59m▄[38;5;232;48;5;239m▄[38;5;232;48;5;235m▄▄[38;5;232;48;5;233m▄[38;5;235;48;5;236m▄[38;5;234;48;5;234m▄[38;5;232;48;5;233m▄[38;5;233;48;5;233m▄[38;5;232;48;5;0m▄[38;5;237;48;5;235m▄[38;5;238;48;5;241m▄[38;5;235;48;5;233m▄[38;5;233;48;5;238m▄[38;5;131;48;5;167m▄[38;5;167;48;5;168m▄[38;5;131;48;5;174m▄[38;5;132;48;5;174m▄[38;5;167;48;5;167m▄[38;5;174;48;5;137m▄[38;5;131;48;5;138m▄[38;5;233;48;5;239m▄[38;5;237;48;5;242m▄[38;5;95;48;5;0m▄[38;5;236;48;5;237m▄[38;5;95;48;5;173m▄[38;5;131;48;5;235m▄[38;5;243;48;5;0m▄[38;5;236;48;5;238m▄[38;5;232;48;5;235m▄[38;5;232;48;5;131m▄[38;5;234;48;5;236m▄[38;5;232;48;5;233m▄[48;5;0m [m",
	"[48;5;0m                              [38;5;232;48;5;0m▄[48;5;m [38;5;233;48;5;233m▄[38;5;233;48;5;0m▄[38;5;232;48;5;0m▄[48;5;0m [38;5;232;48;5;0m▄[38;5;138;48;5;95m▄[38;5;237;48;5;233m▄[38;5;241;48;5;0m▄[38;5;240;48;5;236m▄[38;5;95;48;5;131m▄[38;5;232;48;5;0m▄▄[38;5;235;48;5;95m▄[38;5;233;48;5;236m▄[38;5;232;48;5;236m▄[38;5;232;48;5;0m▄▄[38;5;232;48;5;235m▄[38;5;95;48;5;137m▄[38;5;131;48;5;181m▄[38;5;174;48;5;181m▄[38;5;131;48;5;174m▄[38;5;138;48;5;243m▄[38;5;131;48;5;95m▄[38;5;239;48;5;234m▄[38;5;232;48;5;0m▄[48;5;0m  [m",
	"[48;5;0m                              [38;5;232;48;5;0m▄[38;5;;48;5;236m▄[38;5;233;48;5;234m▄[38;5;234;48;5;234m▄[48;5;0m  [38;5;232;48;5;0m▄[38;5;236;48;5;137m▄[38;5;167;48;5;174m▄[38;5;174;48;5;181m▄[38;5;238;48;5;181m▄[38;5;232;48;5;59m▄[48;5;0m        [38;5;233;48;5;237m▄[38;5;235;48;5;131m▄[38;5;95;48;5;131m▄[38;5;232;48;5;95m▄[38;5;232;48;5;233m▄[38;5;232;48;5;235m▄[38;5;232;48;5;0m▄[48;5;0m   [m",
	"[48;5;0m                              [38;5;232;48;5;0m▄[38;5;235;48;5;235m▄[38;5;234;48;5;234m▄▄[48;5;0m   [38;5;237;48;5;234m▄[38;5;131;48;5;167m▄[38;5;138;48;5;174m▄[38;5;174;48;5;138m▄[38;5;95;48;5;234m▄[48;5;0m          [38;5;232;48;5;233m▄[48;5;0m       [m",
	"[48;5;0m                              [38;5;233;48;5;233m▄[38;5;235;48;5;235m▄▄[48;5;233m [48;5;0m  [38;5;233;48;5;0m▄[38;5;240;48;5;95m▄[38;5;232;48;5;m▄[38;5;232;48;5;233m▄[38;5;232;48;5;95m▄[38;5;232;48;5;239m▄[48;5;0m                  [m",
	"[48;5;0m                              [38;5;233;48;5;233m▄[38;5;;48;5;236m▄[38;5;236;48;5;235m▄[38;5;233;48;5;0m▄[48;5;0m   [38;5;232;48;5;0m▄[48;5;0m                      [m",
	"[48;5;0m                              [38;5;233;48;5;233m▄[38;5;235;48;5;m▄[38;5;236;48;5;236m▄[38;5;232;48;5;233m▄[48;5;0m                          [m",
	"[48;5;0m                              [38;5;233;48;5;233m▄[38;5;;48;5;236m▄[38;5;237;48;5;237m▄[48;5;233m [48;5;0m                          [m",
	"[48;5;0m                              [38;5;234;48;5;233m▄[38;5;237;48;5;m▄▄[38;5;232;48;5;233m▄[48;5;0m                          [m",
	"[48;5;0m                              [38;5;234;48;5;234m▄[38;5;237;48;5;237m▄[38;5;237;48;5;238m▄[38;5;232;48;5;0m▄[48;5;0m                          [m",
	"[48;5;0m                              [38;5;233;48;5;234m▄[38;5;237;48;5;237m▄▄[38;5;232;48;5;0m▄[48;5;0m                          [m",
};
