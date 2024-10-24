/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:34:49 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 15:59:11 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() :
	_name("undefined"),
	_isSigned(false),
	_gradeToSign(150),
	_gradeToExecute(150)
{
	std::cout << "Default constructor called" << std::endl;
}

// Constructor with name, gradeToSign and gradeToExecute
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	std::cout << "Constructor with name " << this->_name << ", gradeToSign " << this->_gradeToSign
			  << " and gradeToExecute " << this->_gradeToExecute << " called." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &other) :
	_name(other._name),
	_isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned; // Other members are const
	}
	return *this;
}

// Destructor
Form::~Form()
{
	std::cout << "Form Destructor called." << std::endl;
}

// Getters
std::string Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

// Setters
void Form::setIsSigned(bool isSigned)
{
	this->_isSigned = isSigned;
}

// Member functions
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

// Exception classes
const char *Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade is too low!";
}

// Overload of the insertion operator
std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName() << ", signed: " << std::boolalpha << form.getIsSigned()
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}