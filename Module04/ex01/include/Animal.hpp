/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:56:26 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 19:35:32 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

/*	Deep copy is important when classes have attributes that point to dynamic
	memory (for example, pointers that point to objects created with new). It
	could also be done like this:
		Animal::operator=(other);  // Copies the Animal part
		delete brain;              // Frees the current memory
		brain = new Brain(*other.brain);  // Deep copy of the Brain.
	(this code is in the Cat & Dog operator assignator).	*/

class Animal
{
	protected:
		// Attributes
		std::string	_type;
		
	public:
		// Constructors & Destructors
		Animal(void);
		Animal(const Animal &other);
		virtual Animal &operator=(const Animal &other);
		virtual ~Animal(void);

		// Methods
		virtual void	makeSound(void) const = 0;
		
		//	Getters
		virtual std::string	get_Type(void) const;
		virtual Brain		*get_brain(void) const;
};
