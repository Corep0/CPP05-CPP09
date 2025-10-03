/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:21:48 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 14:45:57 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	Bureaucrat;

class	RobotomyRequestForm: public AForm
{
	public:
		// Constructor | Destructor
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const& copy);

		// Operator
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

		// Member Function
		void	execute(Bureaucrat const& executor) const;	
		// Getter | Setter
		std::string	getTarget(void) const;
		// Exception class
	private:
		std::string	_target;
};

std::ostream&	operator<<(std::ostream& out, RobotomyRequestForm &f);

#endif // RobotomyRequestForm_HPP
