/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:59:12 by seruff            #+#    #+#             */
/*   Updated: 2025/09/29 14:09:26 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*	TESTER		*/
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
	createBureaucrat("Jack1", 140);
	Form f("5A", false, 30, 40);
	std::cout << f << std::endl;
	return (0);
}
