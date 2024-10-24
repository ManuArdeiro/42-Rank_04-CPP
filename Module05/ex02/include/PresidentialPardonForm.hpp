/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:47:02 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 18:39:37 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		// Default constructor
		PresidentialPardonForm();
		
		// Constructor with target
		PresidentialPardonForm(const std::string &target);

		// Copy constructor
		PresidentialPardonForm(const PresidentialPardonForm &other);

		// Assignment operator
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		// Destructor
		virtual ~PresidentialPardonForm();

		// Execute the form
		virtual void execute(Bureaucrat const &executor) const;
};
