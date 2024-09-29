/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:41:44 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/28 19:34:22 by jolopez-         ###   ########.fr       */
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
		void	makeSound(void) const;
		
		//	Getters
		std::string	get_Type(void) const;
		Brain		*get_brain() const;
};
