/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:21:04 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 19:50:22 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//	Constructor
/*	We need to use the reference in the constructor because if not when we 
	change the Weapon in main() it won't be changed in HumanA.
	HumanA uses a reference to Weapon because it is always armed. The reference
	ensures that the Weapon always exists and does not need additional checks.
	It is more efficient because there is no need for pointer checks and no risk
	of having a nullptr.	*/
HumanA::HumanA(std::string name, Weapon &club) :
	_name(name),
	_weapon(club)
{
}

//	Destructor
HumanA::~HumanA()
{
}

//	Methods
void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType();
	std::cout << "." << std::endl;
}