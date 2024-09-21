/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:40:38 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 19:40:03 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie(void) 
{
    std::cout << "A zombie was created." << std::endl;
}

// Constructor with parameter (name)
Zombie::Zombie(std::string name) : name(name) 
{
}

// Destructor
Zombie::~Zombie()
{
    std::cout << name << " is destroyed." << std::endl;
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
    std::cout << "Zombie has been renamed to " << this->name << std::endl;
}
