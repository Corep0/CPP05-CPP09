/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:06:23 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 09:44:45 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
 * Constructor | Default Constructor | Destructor | Copy Constructor
*/
Bureaucrat::Bureaucrat(void): _name("Default"), _grade(75)
{
	std::cout << "Bureaucrat Default"
		<< " constructor is called with a grade of "
		<< _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->_name = name;
	std::cout << "Bureaucrat " << name
		<< " constructor is called with a grade of "
		<< grade << std::endl;
	setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor is called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy)
{
	std::cout << "Bureaucrat Copy constructor is called" << std::endl;
	*this = copy;
}

/*	Assignement Operator 	*/
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Assignement operator is called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return (*this);
}

/*	Member Function		*/
void Bureaucrat::increment(void)
{
	std::cout << "Incrementing grade for " << this->getName() << std::endl;
	this->setGrade(this->_grade - 1);
}

void Bureaucrat::decrement(void)
{
	std::cout << "Decrementing grade for " << this->getName() << std::endl;
	this->setGrade(this->_grade + 1);
}

/*	Exception Class 	*/
const char*	Bureaucrat::GradeTooHighException::what() const
{
	return ("\033[31mGrade is to high < 1\033[0m");
}

const char*	Bureaucrat::GradeTooLowException::what() const
{
	return ("\033[31mGrade is to low > 150\033[0m");
}

/*	Getter | Setter		*/
std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setName(std::string new_name)
{
	this->_name = new_name;
}

void	Bureaucrat::setGrade(int val)
{
	if (val < 1)
		throw GradeTooHighException();
	else if (val > 150)
		throw GradeTooLowException();
	else
		this->_grade = val;
}

/*	Function	*/
std::ostream& operator<<(std::ostream& out, Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (out);
}

