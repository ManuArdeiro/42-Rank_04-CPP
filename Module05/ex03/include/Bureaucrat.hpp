/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:04:15 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 19:43:02 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

// Forward declaration
class AForm;

/*	
	An exception is a signal that something has gone wrong during the execution
	of a program. In C++, when an exception is thrown, the normal flow of the
	program is interrupted, and control is transferred to an exception handling
	section where the error can be appropriately addressed.

	In C++, exceptions are handled using three main keywords:
		throw:	Used to throw an exception.
		try:	Defines a block of code where an exception might occur.
		catch:	Catches an exception thrown within a try block to handle it.
	
	what() method: The what() method in exceptions returns a message that describes
	the error. This method is overridden in custom exceptions. By calling e.what(),
	we can get a specific message about why the exception was thrown.
*/
class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;

	public:
		// Default constructor
		Bureaucrat();

		// Costructor with name and grade
		Bureaucrat(const std::string &name, int grade);

		// Copy constructor
		Bureaucrat(const Bureaucrat &other);

		// Assignment operator
		Bureaucrat &operator=(const Bureaucrat &other);

		// Destructor
		~Bureaucrat();
		
		// Exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		// Getters
		std::string	getName() const;
		int 		getGrade() const;

		// Increment and decrement grade
		void		incrementGrade();
		void		decrementGrade();
		
		// Methods
		void			signForm(AForm &form);
		virtual void	executeForm(AForm const &form);
};

// Sobrecarga del operador de inserción
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
