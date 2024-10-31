/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 13:15:57 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/17 20:59:14 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

/*	The attributes should now be protected instead of private, I leave one
	private and create the necessary functions to see the difference.	*/
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
		
		//	Copy constructor
		ClapTrap(const ClapTrap &other);

		//	Copy assignment operator
		ClapTrap &operator=(const ClapTrap &other);

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
		//	It's enough to declare the destructor of the base class as virtual, the
		//	derived class will automatically be virtual.
		virtual ~ClapTrap();

		//	Methods
		void attack(ClapTrap &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};