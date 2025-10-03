/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:21:46 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 14:46:35 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class	Bureaucrat;

class PresidentialPardonForm: public AForm
{
	public:
		// Constructor | Destructor
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const& copy);

		// Operator
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		// Member Function
		void	execute(Bureaucrat const& executor) const;
		// Getter | Setter
		std::string	getTarget(void) const;
		// Exception class
	private:
		std::string	_target;
};

std::ostream&	operator<<(std::ostream& out, PresidentialPardonForm& f);

#endif // PresidentialPardonForm_HPP
