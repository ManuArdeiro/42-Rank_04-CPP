/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:34:49 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 19:55:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() :
	_name("undefined"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150)
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor with name, gradeToSign and gradeToExecute
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << "Constructor with name " << this->_name << ", gradeToSign " << this->_gradeToSign
			  << " and gradeToExecute " << this->_gradeToExecute << " called." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned; // Other members are const
	}
	return *this;
}

// Destructor
AForm::~AForm()
{
	std::cout << "AForm Destructor called." << std::endl;
}

// Getters
std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

// Setters
void AForm::setIsSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}

// Member functions
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign && !this->_isSigned)
		this->_isSigned = true;
	else if (this->_isSigned)
		throw AForm::FormSignedException();	
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!this->_isSigned)
		throw AForm::FormSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
}
// Exception classes
const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

const char *AForm::FormSignedException::what() const throw()
{
	return "Form is already signed!";
}

// Overload of the insertion operator
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm: " << form.getName() << ", signed: " << std::boolalpha << form.getIsSigned()
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}