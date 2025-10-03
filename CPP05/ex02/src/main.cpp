/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:47:32 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 15:24:47 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
/*
 * Trouble when grade is too low
 * Crash SIGABORT
 */
int	main(void)
{	
	Bureaucrat *bur = new Bureaucrat("Jean", 21);
	Bureaucrat *bur1 = new Bureaucrat("Jean1", 11);
	Bureaucrat *bur2 = new Bureaucrat("Jean1", 31);
	ShrubberyCreationForm *a = new ShrubberyCreationForm("Home");	
	try{
		a->execute(*bur);
	}
	catch(AForm::GradeTooLowException())
	{
		std::cout << "Can't exec" << std::endl;	
	}
	std::cout << *a;
	delete a;
	std::cout << "-----------------------------" << std::endl;
	PresidentialPardonForm *b = new PresidentialPardonForm("Jean");
	try{
		b->execute(*bur1);
	}
	catch(AForm::GradeTooLowException())
	{
		std::cout << "Can't exec" << std::endl;	
	}
	std::cout << *b;
	delete b;
	std::cout << "-----------------------------" << std::endl;
	RobotomyRequestForm *c = new RobotomyRequestForm("Robot");
	try{
		c->execute(*bur2);
	}
	catch(AForm::GradeTooLowException())
	{
		std::cout << "Can't exec" << std::endl;	
	}
	std::cout << *c;
	delete c;
	std::cout << "-----------------------------" << std::endl;
	delete bur;
	delete bur1;
	delete bur2;

	return (0);
}
