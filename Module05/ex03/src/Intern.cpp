/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:18:01 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 20:32:19 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Default constructor
Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern &other)
{
	std::cout << "Intern Copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern Assignment operator called" << std::endl;
	return *this;
}

// Destructor
Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[] = { "shrubbery creation", "robotomy request", "presidential pardon" };
    FormCreator formCreators[] = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm};

    for (int i = 0; i < 3; ++i)
	{
        if (formName == formNames[i])
		{
            std::cout << "Intern creates " << formNames[i] << " form." << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    std::cout << "Error: Form name \"" << formName << "\" not found." << std::endl;
    return NULL;
}

// Private methods
AForm* Intern::makeShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}