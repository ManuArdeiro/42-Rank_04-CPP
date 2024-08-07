/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:06:48 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/07 19:49:13 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//	Default constructor
Weapon::Weapon(void)
{
}

//	Constructor with parameters
Weapon::Weapon(const std::string name) : _type(name) {}

//	Destructor
Weapon::~Weapon()
{
}

//	Methods
std::string	Weapon::getType(void)
{
	std::string	&reference = this->_type;
	return reference;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
