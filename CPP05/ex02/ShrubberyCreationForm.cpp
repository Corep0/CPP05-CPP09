/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:34:23 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 15:23:56 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructor | Destructor
ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "Default";
	std::cout << "ShrubberyCreationForm Constructor is called for "
	       << getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor is called for "
	       << getTarget() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy)
{
	std::cout << "ShrubberyCreationForm Copy Constructor is called" << std::endl;
	*this = copy;	
}

// Operator
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm Assignement operator is called" << std::endl;
	if (this != &other)
		return (*this);
	return (*this);
}

// Member Function
void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getRequiredExec())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getStateSigned() == false)
		throw(AForm::FileIsNotSigned());
	else
	{
		std::string file_name = this->getTarget() + "_shrubbery";
		std::ofstream	file_target(file_name.c_str());
		file_target << ASCII_TREE << "\n";
		file_target.close();
		std::cout << "ASCII TREE has been copied into the file "
			<< this->getTarget() << std::endl;
	}
}
// Getter | Setter
std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

// Exception class

/*	Function	*/
std::ostream&	operator<<(std::ostream& out, ShrubberyCreationForm& f)
{
	(void)f;
	return (out);
}
