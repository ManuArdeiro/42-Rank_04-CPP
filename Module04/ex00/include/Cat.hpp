/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:41:44 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/24 13:16:11 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		// Attributes
		std::string _type;
		
	public:
		// Constructors & Destructors
		Cat();
		Cat(std::string type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();

		// Methods
		//	In C++11 we'll use the override keyword to explicitly tell the compiler
		//	that we intend to override a virtual function. This is optional, but it
		//	helps to catch errors and make the code easier to read. 
		void	makeSound(void) const;
		
		//	Getters
		std::string	getType(void) const;
};
