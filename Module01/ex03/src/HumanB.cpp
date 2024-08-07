/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:17:56 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/07 19:56:55 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

//	Constructor
/*	HumanB uses a pointer to Weapon because it may not have a weapon at all
	times. A pointer allows representing the absence of a Weapon with a nullptr
	and provides the flexibility to assign a Weapon later. This requires
	additional checks (if (weapon)) before using the Weapon.	*/
HumanB::HumanB(std::string name)
{
	this->_name = name;
}

//Destructor
HumanB::~HumanB()
{
}

//Methods
void	HumanB::attack(void)
{
	if (this->_weapon != NULL)
	{
		std::cout << this->_name << " attacks with their ";
		std::cout << this->_weapon->getType() << "." << std::endl;
	}
	else
	{
		std::cout << this->_name << " attacks with their (empty)." << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &Weapon)
{
	this->_weapon = &Weapon;
}