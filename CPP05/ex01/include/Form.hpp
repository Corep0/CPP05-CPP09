/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:05:42 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 11:23:26 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
# define Form_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		// Constructor | Destructor
		Form();
		Form(std::string name = "Default", bool state_signed = false, int req_sign = 10, int req_exec = 10);
		virtual ~Form();
		Form(Form const& copy);

		// Operator
		Form&	operator=(const Form& other);

		// Member Function
		void	beSigned(Bureaucrat &b);	
		// Getter | Setter
		bool		getStateSigned(void) const;
		int		getRequiredSigned(void) const;
		int		getRequiredExec(void) const;
		std::string	getNameForm(void) const;

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
		const std::string	name;
		bool			state_signed;
		const int		req_sign;
		const int		req_exec;
};

std::ostream& operator<<(std::ostream& out, Form &f);

#endif // Form_HPP
