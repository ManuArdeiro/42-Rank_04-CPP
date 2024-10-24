/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:10:10 by jolopez-          #+#    #+#             */
/*   Updated: 2024/10/15 20:26:42 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

    	AForm* makeForm(const std::string &formName, const std::string &target);
		
	private:
		typedef AForm *(Intern::*FormCreator)(const std::string &target);

		AForm* makeShrubberyCreationForm(const std::string &target);
		AForm* makeRobotomyRequestForm(const std::string &target);
		AForm* makePresidentialPardonForm(const std::string &target);
};
