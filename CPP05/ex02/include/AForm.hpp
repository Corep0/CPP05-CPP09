/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:05:42 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 15:13:09 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		// Constructor | Destructor
		AForm(std::string name = "Default", bool state_signed = false, int req_sign = 10, int req_exec = 10);
		virtual ~AForm();
		AForm(AForm const& copy);

		// Operator
		AForm&	operator=(const AForm& other);

		// Member Function
		void	beSigned(Bureaucrat &b);	
		void	execute(Bureaucrat const& executor) const;
		// Getter | Setter
		bool		getStateSigned(void) const;
		int		getRequiredSigned(void) const;
		int		getRequiredExec(void) const;
		std::string	getNameAForm(void) const;

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
		class	FileIsNotSigned
		{
			public:
				const char* what() const;
		};
		class	FormCantBeExecuted	
		{
			public:
				const char* what() const;
		};
	private:
		const std::string	name;
		bool			state_signed;
		const int		req_sign;
		const int		req_exec;
};

std::ostream& operator<<(std::ostream& out, AForm &f);

#endif // AForm_HPP
