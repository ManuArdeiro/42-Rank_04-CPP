/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:15:57 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 18:47:32 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hit;
		unsigned int	_energy;
		unsigned int	_attack;

	public:
		//	Constructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hit, unsigned int energy,
			unsigned int damage);
		
		//	Copy constructor
		ClapTrap(const ClapTrap &other);

		//	Copy assignment operator
		ClapTrap &operator=(const ClapTrap &other);

		//	Destructor
		//	When you apply virtual to a destructor, it means that if you have a base
		//	class with a virtual destructor and a derived class that overrides that
		//	destructor, the derived class's destructor will be called correctly even
		//	if you delete an object through a pointer to the base class. Defining a
		//	destructor as virtual ensures that C++ will use the correct destructor
		//	in the class hierarchy, meaning it will start with the derived class and
		//	then call the destructors of the base classes in reverse order of
		//	construction. This is crucial to prevent memory leaks or the incorrect
		//	release of resources when working with inheritance.
		virtual ~ClapTrap();

		//	Methods
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
