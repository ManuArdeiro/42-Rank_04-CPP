/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:34:03 by jolopez-          #+#    #+#             */
/*   Updated: 2024/08/17 21:04:23 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors & Destructors:

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_guardGate = false;
	
    std::cout << "\033[32m" << "ScavTrap Default Constructor called.\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_guardGate = false;

    std::cout << "\033[32m" << "ScavTrap Constructor with name called.\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->_hit<< std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name, unsigned int hit, unsigned int energy,
	unsigned int attack) : ClapTrap(name, hit, energy, attack)
{
	this->_guardGate = false;

    std::cout << "\033[32m" << "ScavTrap Constructor called for " << name << ".\n";
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->_guardGate = other._guardGate;

    std::cout << "\033[32m" << "ScavTrap Copy Constructor called for " << this->_name << ".\n";;
	std::cout << "name =  " << this->_name<< std::endl;
	std::cout << "hit points =  " << this->_hit << std::endl;
	std::cout << "energy points =  " << this->_energy << std::endl;
	std::cout << "attack damage =  " << this->_attack << std::endl;
	std::cout << this->_name << "\033[0m" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
		this->_name = other._name;
		this->_hit = other._hit;
		this->_energy = other._energy;
		this->setAttack(other._attack);
		this->_guardGate = other._guardGate;
		
        std::cout << "\033[32m" << "ScavTrap Assignment Operator called.";
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
		std::cout << "\033[0m" << std::endl;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[32m" << "ScavTrap Destructor for " << this->_name;
	std::cout << " called." << "\033[0m" << std::endl;
}

//	Methods:

void ScavTrap::attack(const std::string &target)
{
	
	if (this->_hit >= 1 && this->_energy >= 1)
	{
		std::cout << "\033[32m" << "ScravTrap " << this->_name << " attacks ";
		std::cout << target << ", causing " << this->_attack;
		std::cout << " points of damage!" << "\033[0m" << std::endl;
		this->_energy--;
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
		std::cout << "\033[0m" << std::endl;
	}
	else if (this->_energy == 0)
	{
		std::cout << "\033[32m" << "ScravTrap " << this->_name;
		std::cout << " is not able to attack to " << target;
		std::cout << ", because he has no energy points left.\n" << "\033[0m";
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
		std::cout << "\033[0m" << std::endl;	
	}
	else
	{
		std::cout << "\033[32m" << "ScravTrap " << this->_name;
		std::cout << " is not able to attack to " << target;
		std::cout << ", because he has no hit points left.\n" << "\033[0m";
		std::cout << "name =  " << this->_name<< std::endl;
		std::cout << "hit points =  " << this->_hit << std::endl;
		std::cout << "energy points =  " << this->_energy << std::endl;
		std::cout << "attack damage =  " << this->_attack << std::endl;
		std::cout << "\033[0m" << std::endl;
	}
	return ;
}

void ScavTrap::guardGate(void)
{
	if (this->_guardGate == false)
	{
		this->_guardGate = true;
		std::cout << "\033[32m" << "ScavTrap " << this->_name;
		std::cout << " is now guarding the gate." << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[32m" << "ScavTrap " << this->_name;
		std::cout << " was already guarding the gate." << "\033[0m" << std::endl;
	}
}
