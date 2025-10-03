/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:12:43 by seruff            #+#    #+#             */
/*   Updated: 2025/10/03 15:11:46 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* Creating Bureaucrat *TESTER* */
void	createBureaucrat(const std::string& name, int grade)
{
	try
	{
		Bureaucrat b(name, grade);
		std::cout << b;
	}
	catch (Bureaucrat::GradeTooHighException &error)
	{
		std::cout << "Error: " << error.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &error)
	{
		std::cout << "Error: " << error.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << "\033[1m Testing Bureaucrat creation\033[0m" << std::endl;
	createBureaucrat("Jack", 53);
	createBureaucrat("Jack1", 150);
	createBureaucrat("Jack2", 1);
	createBureaucrat("Jack3", -1);
	createBureaucrat("Jack4", 151);

	std::cout << "\n\033[1m Testing Heap Bureaucrat with name/grade\033[0m" << std::endl;
	Bureaucrat	*a = new Bureaucrat("Joe", 150);
	try{
		a->increment();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << *a;
	}
	std::cout << *a;
	try{
		a->decrement();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << *a;
	}
	std::cout << *a;
	delete a;

	std::cout << "\n\033[1m Testing Heap Bureaucrat withtout name/grade\033[0m" << std::endl;
	Bureaucrat	*b = new Bureaucrat();
	try{
		b->increment();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << *b;
	}
	std::cout << *b;

	try{
		b->decrement();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << *b;
	}
	std::cout << *b;
	delete b;

}
