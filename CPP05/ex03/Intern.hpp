/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:25:59 by seruff            #+#    #+#             */
/*   Updated: 2025/09/30 15:26:01 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class Intern
{
	public:
		// Constructor | Destructor
		Intern();
		virtual ~Intern();
		Intern(Intern const& copy);

		// Operator
		Intern&	operator=(const Intern& other);

		// Member Function
		
		// Getter | Setter

		// Exception class
	private:

};

#endif // Intern_HPP
