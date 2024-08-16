/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:41:10 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/15 18:40:14 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    this->_name = "no_one";
	ClapTrap::_name = "no_one_clap_name";
    this->_hit = FragTrap::_hit;  // FragTrap inheritance
    this->_energy = ScavTrap::_energy;  // ScavTrap inheritance
    this->_attack = FragTrap::_attack;  // FragTrap inheritance
    std::cout << "\033[35m" << "DiamondTrap Default Constructor called for " << this->_name << std::endl;
	std::cout << "\033[35m" << "name =  " << this->_name<< std::endl;
	std::cout << "\033[35m" << "ClapTrap name =  " << ClapTrap::_name << std::endl;
	std::cout << "\033[35m" << "hit points =  " << this->_hit << std::endl;
	std::cout << "\033[35m" << "energy points =  " << this->_energy << std::endl;
	std::cout << "\033[35m" << "attack damage =  " << this->_attack<< "\033[0m"  << std::endl;
}

// Constructor with name
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->_name = name;
    this->_hit = FragTrap::_hit;  // FragTrap inheritance
    this->_energy = ScavTrap::_energy;  // ScavTrap inheritance
    this->_attack = FragTrap::_attack;  // FragTrap inheritance
    std::cout<< "\033[35m"  << "DiamondTrap Constructor called for " << this->_name << std::endl;
	std::cout << "\033[35m" << "name =  " << this->_name<< std::endl;
	std::cout << "\033[35m" << "ClapTrap name =  " << ClapTrap::_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack<< "\033[0m"  << std::endl;
}

// Constructor with name and parameters
DiamondTrap::DiamondTrap(std::string name, unsigned int hit, unsigned int energy,
	unsigned int attack) : ClapTrap(name + "_clap_name", hit, energy, attack)
{
    this->_name = name;
    this->_hit = FragTrap::_hit;  // FragTrap inheritance
    this->_energy = ScavTrap::_energy;  // ScavTrap inheritance
    this->_attack = FragTrap::_attack;  // FragTrap inheritance

    std::cout << "\033[35m" << "DiamondTrap Constructor called for " << name << ".\n";
	std::cout << "\033[35m" << "name =  " << this->_name<< std::endl;
	std::cout << "\033[35m" << "ClapTrap name =  " << ClapTrap::_name << std::endl;
	std::cout << "\033[35m" << "hit points =  " << this->getHit() << std::endl;
	std::cout << "\033[35m" << "energy points =  " << this->getEnergy() << std::endl;
	std::cout << "\033[35m" << "attack damage =  " << this->getAttack() << std::endl;
	std::cout << "\033[0m" << std::endl;
}


// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    *this = other;
    std::cout << "\033[35m" << "DiamondTrap Copy Constructor called for ";
	std::cout << this->_name << std::endl;
	std::cout << "\033[35m" << "name =  " << this->_name<< std::endl;
	std::cout << "\033[35m" << "ClapTrap name =  " << ClapTrap::_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

// Operador de asignación
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_name = other._name;
        this->_hit = other._hit;
        this->_energy = other._energy;
        this->_attack = other._attack;
    }
    std::cout << "\033[35m" << "DiamondTrap Assignment Operator called for ";
	std::cout << this->_name << std::endl;
	std::cout << "\033[35m" << "name =  " << this->_name<< std::endl;
	std::cout << "\033[35m" << "ClapTrap name =  " << ClapTrap::_name << std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "\033[35m" << "DiamondTrap Destructor for ";
	std::cout << this->_name << std::cout << "\033[0m" << std::endl;
}

// Method whoAmI
void DiamondTrap::whoAmI()
{
    std::cout << "\033[32m" << "DiamondTrap name is " << this->_name;
	std::cout << " and ClapTrap name is " << ClapTrap::_name << std::endl;
}

// Method attack (use the ScavTrap attack)
void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}
