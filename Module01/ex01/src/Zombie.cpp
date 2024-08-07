/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:40:38 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/03 22:24:29 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie(void) 
{
}

// Constructor with parameter (name)
Zombie::Zombie(std::string name) : name(name) {}

// Destructor
Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}

// Announce method
void Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Set name method
void	Zombie::set_name(std::string name)
{
	this->name = name;
}
