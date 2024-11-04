/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:41:03 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 19:57:07 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45),
	_target("undefined")
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor with target
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	std::cout << "Constructor with target " << this->_target << " called." << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other),
	_target(other._target)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->_target = other._target; // Other members are const
	}
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called." << std::endl;
}

// Execute the form
void RobotomyRequestForm::executeAction() const
{
	// Execute the form
	std::cout << " *drilling noises* " << std::endl;
	if (rand() % 2)
	{
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	}
	else
	{
		std::cout << this->_target << " robotomization failed." << std::endl;
	}
}
