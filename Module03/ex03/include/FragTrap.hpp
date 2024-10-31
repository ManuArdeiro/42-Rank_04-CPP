/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:03:14 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 18:44:00 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

/*	The DiamondTrap class will inherit from FragTrap and ScavTrap. Since both
	classes derive from ClapTrap, we need to ensure that the ClapTrap subobject
	is created only once. The way to achieve this is by ensuring that both
	FragTrap and ScavTrap inherit from ClapTrap virtually. This is necessary to
	avoid ambiguity and duplication of members in the derived class.	*/
	
class FragTrap: virtual public ClapTrap
{
	private:
		
	public:
		//	Constructors:
		FragTrap();
		FragTrap(std::string name);

		//	Copy Constructor:
		FragTrap(const FragTrap &other);

		//	Copy assignment operator:
		FragTrap &operator=(const FragTrap &other);

		//	Destructor:
		~FragTrap();
		
		//	Methods:
		void attack(FragTrap &target);
		void highFivesGuys(void);
};