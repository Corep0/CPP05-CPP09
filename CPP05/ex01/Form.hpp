/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:34:35 by seruff            #+#    #+#             */
/*   Updated: 2025/09/29 14:12:45 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class	Form
{
	public:
		// Constructor | Destructor
		Form();
		virtual ~Form();
		Form(std::string name, bool state, int grade_sign, int grade_exec);
		Form(Form const& copy);
		
		// Operator
		Form&	operator=(const Form& other);

		// Exception class
		class	GradeTooLowException
		{
			public:
				const char* what() const;
		};
		class	GradeTooHighException
		{
			public:
				const char* what() const;
		};
		// Member Function
			
		// Getter
		std::string	getNameForm(void) const;
		bool		getState(void) const;
		int		getSignedGrade(void) const;
		int		getExecuteGrade(void) const;
	private:
		std::string name;
		bool	signed_state;
		int	grade_sign;
		int	grade_exec;
};

std::ostream& operator<<(std::ostream& out, const Form &f);
#endif //FORM_HPP
