/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:16:20 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 18:39:41 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		// Default constructor
		ShrubberyCreationForm();
		
		// Constructor with target
		ShrubberyCreationForm(const std::string &target);

		// Copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other);

		// Assignment operator
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		// Destructor
		virtual ~ShrubberyCreationForm();

		// Execute the form
		virtual void execute(Bureaucrat const &executor) const;
};
