/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:25:04 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 19:34:28 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		// Attributes
		Brain		*_brain;
		
	public:
		// Constructors & Destructors
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		// Methods
		void	makeSound(void) const;
		
		//	Getters
		std::string	get_Type(void) const;
		Brain		*get_brain() const;
};
