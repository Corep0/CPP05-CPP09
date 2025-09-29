/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:12:43 by seruff            #+#    #+#             */
/*   Updated: 2025/09/29 12:33:11 by seruff           ###   ########.fr       */
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
	createBureaucrat("Jack", 53);
	createBureaucrat("Jack1", 150);
	createBureaucrat("Jack2", 1);
	createBureaucrat("Jack3", -1);
	createBureaucrat("Jack4", 151);
}
