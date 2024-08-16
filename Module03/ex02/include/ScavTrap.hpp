/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:33:35 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/13 13:38:22 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		bool _guardGate;
		
	public:
		//	Constructors:
		ScavTrap();
		ScavTrap(std::string name, unsigned int hit, unsigned int energy,
			unsigned int attack);
		ScavTrap(std::string name);

		//	Copy Constructor:
		ScavTrap(const ScavTrap &other);

		//	Copy assignment operator:
		ScavTrap &operator=(const ScavTrap &other);

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
		~ScavTrap();
		
		//	Methods:
		void attack(const std::string &target);
		void guardGate(void);
};