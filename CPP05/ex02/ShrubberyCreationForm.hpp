/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:32:13 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 15:02:48 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include <iostream>
# include "AForm.hpp"

class	Bureaucrat;

class	ShrubberyCreationForm: public AForm
{
	public:
		// Constructor | Destructor
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const& copy);

		// Operator
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		// Member Function
		void	execute(Bureaucrat const& executor) const;
		// Getter | Setter
		std::string	getTarget(void) const;
		// Exception class
	private:
		std::string	_target;
};

std::ostream&	operator<<(std::ostream& out, ShrubberyCreationForm& f);

# define ASCII_TREE "     X\n    XXX\n   XXXXX\n  XXXXXXX\n   XXXXX\n"

#endif // ShrubberyCreationForm_HPP
