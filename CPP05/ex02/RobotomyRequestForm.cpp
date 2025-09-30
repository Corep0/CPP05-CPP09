/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:34:17 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 15:23:06 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructor | Destructor
RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "Default";
	std::cout << "RobotomyRequestForm Constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor is called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy)
{
	std::cout << "RobotomyRequestForm Copy Constructor is called" << std::endl;
	*this = copy;
}

// Operator
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "RobotomyRequestForm Assignement operator is called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

// Member Function
void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if ((int)executor.getGrade() > this->getRequiredExec())
		throw(AForm::GradeTooLowException());
	else if (this->getStateSigned() == false)
		throw(AForm::FileIsNotSigned());
	else
	{
		std::cout << "*Drilling noise*" << std::endl;
	}
}
/* Getter | Setter	*/
std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}
/* Exception class	*/

/*	Function	*/
std::ostream&	operator<<(std::ostream& out, RobotomyRequestForm& f)
{
	(void)f;
	return (out);
}
