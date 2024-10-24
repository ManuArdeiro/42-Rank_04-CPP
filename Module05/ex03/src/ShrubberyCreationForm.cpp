/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:26:11 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 19:57:23 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), 
	_target("default") 
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

// Constructor with target
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	std::cout << "ShrubberyCreationForm constructor with target " << this->_target << " called." << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other),
	_target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

// Assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
	{
        AForm::operator=(other); // Call the base class assignment operator
        this->_target = other._target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

// Execute the form
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    // Check if the form is signed
    if (!this->getIsSigned())
	{
        throw FormNotSignedException();
    }
	// Check if the executor has the right grade
    if (executor.getGrade() > this->getGradeToExecute())
	{
        throw GradeTooLowException();
    }

    std::ofstream outfile((this->_target + "_shrubbery").c_str());
    if (outfile.is_open())
	{
        outfile << "ASCII Tree\n";
        outfile.close();
        std::cout << "Shrubbery form executed, ASCII tree created.\n";
    }
	else
        std::cerr << "Error: Unable to create shrubbery file.\n";
}
