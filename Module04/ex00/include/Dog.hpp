/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:25:04 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/24 13:16:29 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		// Attributes
		std::string _type;
		
	public:
		// Constructors & Destructors
		Dog();
		Dog(std::string type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		// Methods
		//	In C++11 we'll use the override keyword to explicitly tell the compiler
		//	that we intend to override a virtual function. This is optional, but it
		//	helps to catch errors and make the code easier to read. 
		void	makeSound(void) const;
		
		//	Getters
		std::string	getType(void) const;
};
