/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:08:29 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 15:46:46 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() :
	_name("undefined"),
	_grade(150) 
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor with name and grade
Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	_name(name),
	_grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other._name),
	_grade(other._grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
	{
        this->_grade = other._grade; // We can't change the name of a bureaucrat becasue it's const
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called." << std::endl;
}

// Getters
std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

// Increment and decrement grade
void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    --this->_grade;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    ++this->_grade;
}

// Exception classes
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

// Insertion operator overload
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
