/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:03:14 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 00:58:54 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
	
	public:
		//	Constructors:
		FragTrap();
		FragTrap(std::string name, unsigned int hit, unsigned int energy,
			unsigned int attack);
		FragTrap(std::string name);

		//	Copy Constructor:
		FragTrap(const FragTrap &other);

		//	Copy assignment operator:
		FragTrap &operator=(const FragTrap &other);

		//	Destructor:
		//	When you apply virtual to a destructor, it means that if you have a base
		//	class with a virtual destructor and a derived class that overrides that
		//	destructor, the derived class's destructor will be called correctly even
		//	if you delete an object through a pointer to the base class. Defining a
		//	destructor as virtual ensures that C++ will use the correct destructor
		//	in the class hierarchy, meaning it will start with the derived class and
		//	then call the destructors of the base classes in reverse order of
		//	construction. This is crucial to prevent memory leaks or the incorrect
		//	release of resources when working with inheritance.
		~FragTrap();
		
		//	Methods:
		void attack(const std::string &target);
		void highFivesGuys(void);
};