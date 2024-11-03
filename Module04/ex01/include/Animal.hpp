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
	(this code is in the Cat & Dog operator assignator).	
	
	Virtual destructor:
	When a destructor is not virtual in a base class, and you delete an object
	of a derived class through a pointer to the base class, the destructor of
	the derived class will not be called. This causes an "incomplete destruction"
	where only the base class destructor is called, neglecting any cleanup that
	the derived class destructor should perform.
	Example:
		Suppose you have the following class structure:

			class Animal
			{
			public:
				Animal() { std::cout << "Animal created\n"; }
				~Animal() { std::cout << "Animal destroyed\n"; } // No virtual here
			};

			class Dog : public Animal
			{
			public:
				Dog() { std::cout << "Dog created\n"; }
				~Dog() { std::cout << "Dog destroyed\n"; }
			};

		And then you do the following in main:

			int main()
			{
				Animal* animal = new Dog();
				delete animal; // The Dog destructor will not be called without a virtual destructor in Animal
				return 0;
			}

		Result: The output will be:

			Animal created
			Dog created
			Animal destroyed

		The Dog destructor is never called, which is a problem because any
		resources Dog may have allocated will not be freed, potentially causing
		a memory leak or resource issues.	*/

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
		virtual std::string	getType(void) const;
		virtual Brain		*getBrain(void) const;
};
