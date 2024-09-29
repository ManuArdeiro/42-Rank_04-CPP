/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:12:12 by jolopez-          #+#    #+#             */
/*   Updated: 2024/09/24 13:16:24 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		// Attributes
		std::string _type;
		
	public:
		// Constructors & Destructors
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat();

		// Methods
		//	In C++11 we'll use the override keyword to explicitly tell the compiler
		//	that we intend to override a virtual function. This is optional, but it
		//	helps to catch errors and make the code easier to read. 
		void	makeSound(void) const;
		
		//	Getters
		std::string	getType(void) const;
};
