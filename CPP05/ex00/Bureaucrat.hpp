/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:07:41 by seruff            #+#    #+#             */
/*   Updated: 2025/09/29 14:14:45 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
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
		Bureaucrat  operator++(int);
		Bureaucrat  operator--(int);
		
		// Getter | Setter
		std::string	getName(void) const;
		int		getGrade(void) const;
		
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
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif // BUREAUCRAT_HPP
