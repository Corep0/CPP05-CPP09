/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:05:37 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 15:12:14 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructor | Destructor
AForm::AForm(std::string name, bool state_signed, int req_sign, int req_exec):
	name(name), state_signed(state_signed), req_sign(req_sign), req_exec(req_exec)
{
	const int	a = req_sign;
	const int	b = req_exec;
	if (a < 1 || b < 1)
		throw GradeTooHighException();
	else if (a > 150 || b > 150)
		throw GradeTooLowException();
	std::cout << "AForm Construtor is called for the AForm " << this->name << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor is called for the AForm " << this->name << std::endl;
}

AForm::AForm(AForm const& copy): name(copy.getNameAForm()), state_signed(false)
			      , req_sign(copy.getRequiredSigned()), req_exec(copy.getRequiredExec())
{
	std::cout << "AForm copy is called" << std::endl;
	*this = copy;
}

// Operator
AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "Assignement operator is called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

// Member Function
void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->req_sign && getStateSigned() != true)
	{
		std::cout << "Bureaucrat " << b.getName() << " signed AForm "
			<< this->name << std::endl;
		this->state_signed = true;
	}
	else if (b.getGrade() <= this->req_sign && getStateSigned() == true)
	{
		std::cout << "AForm " << getNameAForm() << " is already signed" << std::endl;
	}
	else
	{
		std::cout << "Bureaucrat " << b.getName()
			<< " couldn't sign AForm " << this->name
			<< " because ";
		throw(Bureaucrat::GradeTooLowException());
	}
}
void	AForm::execute(Bureaucrat const& executor) const
{
	(void)executor;
}

// Getter | Setter
std::string	AForm::getNameAForm(void) const
{
	return (this->name);
}

bool		AForm::getStateSigned(void) const
{
	return (this->state_signed);
}

int		AForm::getRequiredSigned(void) const
{
	return (this->req_sign);
}

int		AForm::getRequiredExec(void) const
{
	return (this->req_exec);
}

// Exception class
const char*	AForm::GradeTooHighException::what() const
{
	return ("\033[31mGrade is to high < 1\033[0m");
}

const char*	AForm::GradeTooLowException::what() const
{
	return ("\033[31mGrade is to low > 150\033[0m");
}

const char*	AForm::FileIsNotSigned::what() const
{
	return ("\033[31mCan't exec because File isn't not signed\033[0m");
}

const char*	AForm::FormCantBeExecuted::what() const
{
	return ("\033[31mCan't exec because grade isn't high enough\033[0m");
}

// Function
std::ostream&	operator<<(std::ostream& out, AForm &f)
{
	std::string	bool_state;

	if (f.getStateSigned() == true)
		bool_state = "signed";
	else
		bool_state = "not signed";
	out << "AForm " << f.getNameAForm() << " is "
		<< bool_state << " grade required to be signed is "
		<< f.getRequiredSigned() << " grade required to be exec is "
		<< f.getRequiredExec() << std::endl;
	return (out);
}
