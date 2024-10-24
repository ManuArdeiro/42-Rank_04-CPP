/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:39:21 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 18:39:20 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		// Default constructor
		RobotomyRequestForm();
		
		// Constructor with target
		RobotomyRequestForm(const std::string &target);

		// Copy constructor
		RobotomyRequestForm(const RobotomyRequestForm &other);

		// Assignment operator
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		// Destructor
		virtual ~RobotomyRequestForm();

		// Execute the form
		virtual void execute(Bureaucrat const &executor) const;
};
