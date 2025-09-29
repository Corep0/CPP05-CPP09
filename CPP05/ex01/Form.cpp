/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:35:37 by seruff            #+#    #+#             */
/*   Updated: 2025/09/29 14:18:00 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*	Constructor | Destructor | Copy */
Form::Form():name("Default"), signed_state(false)
{
	this->grade_sign = 10;
	this->grade_exec = 40;
	std::cout << "Form constructor is called by Default" << std::endl;
}
Form::Form(std::string name, bool signed_state, int grade_sign, int grade_exec):
	name(name), signed_state(signed_state)
{
	if (grade_sign < 1)
		throw GradeTooHighException();
	else if (grade_sign > 150)
		throw GradeTooLowException();
	this->grade_sign = grade_sign;
	if (grade_exec < 1)
		throw GradeTooHighException();
	else if (grade_exec > 150)
		throw GradeTooLowException();
	this->grade_exec = grade_exec;
	std::cout << "Form constructor is called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor is called" << std::endl;
}

Form::Form(Form const& copy)
{
	std::cout << "Copy constructor is called" << std::endl;
	this->name = copy.name;
	this->signed_state = copy.signed_state;
	this->grade_sign = copy.grade_sign;
	this->grade_exec = copy.grade_exec;
}

/*	Operator	*/
Form&	Form::operator=(const Form& other)
{
	std::cout << "Assignement operator is called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->signed_state = other.signed_state;
		this->grade_sign = other.grade_sign;
		this->grade_exec = other.grade_exec;
	}
	return (*this);
}
/*	Stream operator (printer)	*/
std::ostream& operator<<(std::ostream& out, const Form& f)
{
	std::cout << "Form name: " << f.getNameForm()
		<< "\nState if signed: " << f.getState()
		<< "\nGrade required to sign: " << f.getSignedGrade()
		<< "\nGrade required to execute: " << f.getExecuteGrade()
		<< std::endl;
	return (out);
}

/*	Getter		*/
std::string	Form::getNameForm(void) const
{
	return (this->name);
}

bool	Form::getState(void) const
{
	return (this->signed_state);
}

int	Form::getSignedGrade(void) const
{
	return (this->grade_sign);
}

int	Form::getExecuteGrade(void) const
{
	return (this->grade_exec);
}

/*	Exceptions class	*/
const char*	Form::GradeTooLowException::what() const
{
	return ("Grade is to low");
}

const char*	Form::GradeTooHighException::what() const
{
	return ("Grade is to high");
}
