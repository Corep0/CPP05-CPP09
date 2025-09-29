/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:06:23 by seruff            #+#    #+#             */
/*   Updated: 2025/09/29 14:13:59 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
 * Constructor | Default Constructor | Destructor | Copy Constructor
*/
Bureaucrat::Bureaucrat()
{
	this->_name = "Default";
	this->_grade = 75;
	std::cout << "Bureaucrat constructor called by Default" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->_name = name;
	std::cout << "Initial grade is : " << grade << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy)
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else if (this->_grade - 1 > 150)
		throw GradeTooLowException();
	this->_name = copy._name;
	this->_grade = copy._grade;
	std::cout << "Copied constructor called" << std::endl;
}

/*
 * Assignement Operator
*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Assignement operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else if (this->_grade - 1 > 150)
		throw GradeTooLowException();
	Bureaucrat	temp(*this);
	this->_grade -= 1;
	return (temp);
}

Bureaucrat Bureaucrat::operator--(int)
{
	if (this->_grade + 1 < 1)
		throw GradeTooHighException();
	else if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	Bureaucrat	temp(*this);
	this->_grade += 1;
	return (temp);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (out);
}


/*
 * Getter | Setter
*/
std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}


/*
 * Exception Class 
*/
const char*	Bureaucrat::GradeTooHighException::what() const
{
	return ("Grade is to high < 1");
}

const char*	Bureaucrat::GradeTooLowException::what() const
{
	return ("Grade is to low > 150");
}
