/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:59:12 by seruff            #+#    #+#             */
/*   Updated: 2025/10/03 15:15:04 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat *bur = new Bureaucrat();
	std::cout << *bur;
	Form *f = new Form("5A", false, 30, 40);
	std::cout << *f;
	try{
		f->beSigned(*bur);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Grade " << bur->getGrade() << " isn't enough to sign "
			<< "the form " << f->getNameForm() << std::endl;
	}
	delete f;
	delete bur;

	std::cout << "\n\033[1m-------------------------------------------------\033[0m\n";
	Bureaucrat *bur1 = new Bureaucrat("Jackie", 9);
	std::cout << *bur1;
	Form *a = new Form("1A", false, 10);
	std::cout << *a;
	try{
		bur1->signForm(*a);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Grade " << bur1->getGrade() << " isn't enough to sign "
			<< "the form " << a->getNameForm() << std::endl;
	}
	std::cout << *a;
	std::cout << "\n\033[1m-------------------------------------------------\033[0m\n";
	try{
		a->beSigned(*bur1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Grade " << bur1->getGrade() << " isn't enough to sign "
			<< "the form " << a->getNameForm() << std::endl;
	}
	std::cout << *a;
	delete bur1;
	delete a;
	std::cout << "\n\033[1m-------------------------------------------------\033[0m\n";

	Bureaucrat *bur2 = new Bureaucrat("Assistant", 149);
	Bureaucrat *boss = new Bureaucrat("Boss", 1);
	Form *b = new Form("1B", false, 2);
	std::cout << *b;
	std::cout << *bur2;
	std::cout << *boss;
	try{
		bur2->signForm(*b);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Grade " << bur->getGrade() << " isn't enough to sign "
			<< "the form " << b->getNameForm() << std::endl;
	}
	std::cout << *b;
	try{
		boss->signForm(*b);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Grade " << bur->getGrade() << " isn't enough to sign "
			<< "the form " << b->getNameForm() << std::endl;
	}
	std::cout << *b;
	delete b;
	delete boss;
	delete bur2;
	return (0);
}
