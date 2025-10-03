/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:07:41 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 15:10:40 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	public:
		// Constructor | Default constructor | Destructor | Copy constructor
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		virtual ~Bureaucrat();
		Bureaucrat(Bureaucrat const& copy);
		
		// Operator
		Bureaucrat& operator=(const Bureaucrat& other);
		
		// Member Function
		void	increment(void);
		void	decrement(void);
		void	signForm(AForm &form);
		void	executeForm(AForm const& form) const;

		// Getter | Setter
		std::string	getName(void) const;
		int		getGrade(void) const;
		void		setGrade(int val);
		void		setName(std::string new_name);
		
		// Exception class
		class	GradeTooHighException
		{
			public:
				const char* what() const; 
		};
		class	GradeTooLowException
		{
			public:
				const char* what() const;
		};
	private:
		std::string	_name;
		int		_grade;
};

void	createBureaucrat(const std::string& name, int grade);
std::ostream& operator<<(std::ostream& out, Bureaucrat& b);

#endif // BUREAUCRAT_HPP
