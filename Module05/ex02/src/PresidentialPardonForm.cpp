/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:48:12 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 19:57:20 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : 	AForm("PresidentialPardonForm", 25, 5),
	_target("undefined")
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

// Constructor with target
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	std::cout << "PresidentialPardonForm Constructor with target " << this->_target << " called." << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other),
	_target(other._target)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

// Assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->_target = other._target; // Other members are const
	}
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called." << std::endl;
}

// Execute the form
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	// Check if the form is signed
	if (!this->getIsSigned())
	{
		throw AForm::FormNotSignedException();
	}
	// Check if the executor has the right grade
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
