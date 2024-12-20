/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:25:36 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 19:51:11 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib> // rand() and srand()
#include "Bureaucrat.hpp"

// Forward declaration
class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	protected:
		virtual void executeAction() const = 0;

	public:
		// Constructors
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm &operator=(const AForm &other);

		// Destructor
		virtual ~AForm();

		// Exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
    	class FormNotSignedException : public std::exception
		{
        	public:
				const char *what() const throw();
		};
		
    	class FormSignedException : public std::exception
		{
        	public:
				const char *what() const throw();
		};

		// Getters
		std::string getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		// Setters
		void		setIsSigned(bool isSigned);

		// Member functions
		void	beSigned(const Bureaucrat &bureaucrat);
		void	execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream& os, const AForm& form);
