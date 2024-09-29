/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:26:37 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/24 18:37:05 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

/*	Polymorphism is one of the core principles of object-oriented programming (OOP),
	alongside inheritance, encapsulation, and abstraction. In simple terms,
	polymorphism means "many forms" and allows objects of different classes to be
	treated as objects of a common base class. Each object can behave differently
	based on its actual derived class, even if it is referred to through a pointer
	or reference to the base class.

	There are two main types of polymorphism in C++:

	->	Compile-time Polymorphism (or static polymorphism):
		This type of polymorphism is achieved using function overloading or operator
		overloading.
		It occurs when the compiler decides which function or operator to invoke
		based on the function signature (the types and number of parameters) at
		compile time.

	->	Runtime Polymorphism (or dynamic polymorphism):
		This is the polymorphism associated with inheritance and virtual functions.
		It occurs when a base class defines a virtual function, and derived classes
		override that function.
		When a pointer or reference to a base class points to an object of a derived
		class, the overridden function in the derived class is invoked, rather than
		the base class function. This decision is made at runtime.	
		
	By the way:

	->	Inheritance: It focuses on reusing the existing code and creating a new class
		based on an existing class. It is a code reusability technique.
	
	->	Encapsulation: It focuses on hiding the internal details of a class and providing
		controlled access through public methods. It is a data protection technique.

	->	Abstraction: It focuses on hiding unnecessary complexity from the end user and
		showing only the essential aspects. It is a design simplification technique.	*/

class WrongAnimal
{
	protected:
		// Attributes
		std::string _type;
		
	public:
		// Constructors & Destructors
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		virtual WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal();

		// Methods
		void	makeSound(void) const;
		
		//	Getters
		virtual std::string	getType(void) const;
};
