/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:25:36 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/29 21:35:37 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

// Forward declaration
class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		// Constructors
		Form();
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		Form &operator=(const Form &other);

		// Destructor
		~Form();

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

		// Getters
		std::string getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		// Setters
		void		setIsSigned(bool isSigned);

		// Member functions
		void		beSigned(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream& os, const Form& form);
