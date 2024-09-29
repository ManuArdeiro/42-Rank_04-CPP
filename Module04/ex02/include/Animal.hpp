/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:56:26 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 20:06:45 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

/*	To make the Animal class non-instantiable, you can turn it into an abstract
	class. In C++, a class becomes abstract when it has AT LEAST one pure virtual
	method. A pure virtual method is one that has no implementation in the base
	class and must be overridden in the derived classes. This is achieved by
	adding = 0 at the end of the method declaration.

	In this case, since Animal objects should not be instantiable, we can make
	the makeSound() method a pure virtual function. This will prevent Animal from
	being instantiated directly, but it will allow derived classes like Dog and
	Cat to provide their own implementation of this method.	
	
	In C++11 we'll use the override keyword (in Dog & Cat makeSound() function
	to explicitly tell the compiler that we intend to override a virtual function.
	This is optional, but it 	helps to catch errors and make the code easier to
	read. */

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
