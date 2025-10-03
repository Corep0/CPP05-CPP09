/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:05:37 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 12:14:47 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructor | Destructor
Form::Form(std::string name, bool state_signed, int req_sign, int req_exec):
	name(name), state_signed(state_signed), req_sign(req_sign), req_exec(req_exec)
{
	const int	a = req_sign;
	const int	b = req_exec;
	if (a < 1 || b < 1)
		throw GradeTooHighException();
	else if (a > 150 || b > 150)
		throw GradeTooLowException();
	std::cout << "Form Construtor is called for the form " << this->name << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor is called for the form " << this->name << std::endl;
}

Form::Form(Form const& copy): name(copy.getNameForm()), state_signed(false)
			      , req_sign(copy.getRequiredSigned()), req_exec(copy.getRequiredExec())
{
	std::cout << "Form copy is called" << std::endl;
	*this = copy;
}

// Operator
Form&	Form::operator=(const Form& other)
{
	std::cout << "Assignement operator is called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

// Member Function
void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->req_sign && getStateSigned() != true)
	{
		std::cout << "Bureaucrat " << b.getName() << " signed form "
			<< this->name << std::endl;
		this->state_signed = true;
	}
	else if (b.getGrade() <= this->req_sign && getStateSigned() == true)
	{
		std::cout << "Form " << getNameForm() << " is already signed" << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat " << b.getName()
			<< " couldn't sign form " << this->name
			<< " because ";
		throw(Bureaucrat::GradeTooLowException());
	}
		
}

// Getter | Setter
std::string	Form::getNameForm(void) const
{
	return (this->name);
}

bool		Form::getStateSigned(void) const
{
	return (this->state_signed);
}

int		Form::getRequiredSigned(void) const
{
	return (this->req_sign);
}

int		Form::getRequiredExec(void) const
{
	return (this->req_exec);
}

// Exception class
const char*	Form::GradeTooHighException::what() const
{
	return ("\033[31mGrade is to high < 1\033[0m");
}

const char*	Form::GradeTooLowException::what() const
{
	return ("\033[31mGrade is to low > 150\033[0m");
}

// Function
std::ostream&	operator<<(std::ostream& out, Form &f)
{
	std::string	bool_state;

	if (f.getStateSigned() == true)
		bool_state = "signed";
	else
		bool_state = "not signed";
	out << "Form " << f.getNameForm() << " is "
		<< bool_state << " grade required to be signed is "
		<< f.getRequiredSigned() << " grade required to be exec is "
		<< f.getRequiredExec() << std::endl;
	return (out);
}
