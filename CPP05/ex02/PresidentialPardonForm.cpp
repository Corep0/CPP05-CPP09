/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:21:54 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 14:41:50 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructor | Destructor
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardon", 25, 5)
{
	this->_target = "Default";
	std::cout << "PresidentialPardon Constructor is called for "
		<< getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardon Constructor is called for "
	       << getTarget() << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardon Destructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy)
{
	std::cout << "PresidentialPardonForm Copy constructor is called" << std::endl;
	*this = copy;
}

// Operator
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "Assignement operator is called" << std::endl;
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

// Member Function
void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getRequiredExec())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getStateSigned() == false)
		throw(AForm::FileIsNotSigned());
	else
		std::cout << this->getTarget() << "has been pardoned by Zaphod Beeblebrox"
			<< std::endl;
}

// Getter | Setter
std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

// Exception class
/*	Function	*/
std::ostream&	operator<<(std::ostream& out, PresidentialPardonForm& f)
{
	(void)f;
	return (out);
}
