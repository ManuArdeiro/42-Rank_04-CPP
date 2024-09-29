/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:41:44 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 20:05:39 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		// Attributes
		Brain		*_brain;
		
	public:
		// Constructors & Destructors
		Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat(void);

		// Methods
		//	In C++11 we'll use the override keyword to explicitly tell the compiler
		//	that we intend to override a virtual function. This is optional, but it
		//	helps to catch errors and make the code easier to read. 
		void	makeSound(void) const;
		
		//	Getters
		std::string	get_Type(void) const;
		Brain		*get_brain() const;
};
